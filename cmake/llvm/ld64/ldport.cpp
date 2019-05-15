#define LDPORT_CPP
#include <errno.h>
#include <fcntl.h>
#include <libkern/OSAtomic.h>
#include <libunwind/InternalMacros.h>
#include <limits.h>
#include <mach/mach_host.h>
#include <mach/mach_time.h>
#include <memory>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

int (*real_fcntl)(int fd, int cmd, ...) = fcntl;

// See: `llvm/lib/Support/Unix/Path.inc`
int fcntl_getpath(int fd, char *path) {
    static const bool HAS_PROC_SELF_FD = (::access("/proc/self/fd", R_OK) == 0);
    if (HAS_PROC_SELF_FD) {
        char proc[64];
        snprintf(proc, sizeof(proc), "/proc/self/fd/%d", fd);
        ssize_t ret = ::readlink(proc, path, PATH_MAX);
        if (ret > 0) {
            return 0;
        }
    }
    return EINVAL;
}

kern_return_t host_statistics(
    host_t host_priv,
    host_flavor_t flavor,
    host_info_t host_info_out,
    mach_msg_type_number_t *host_info_outCnt
) {
    return ENOTSUP;
}

kern_return_t mach_timebase_info(mach_timebase_info_t info) {
    info->numer = 1000;
    info->denom = 1;
    return 0;
}

uint64_t mach_absolute_time() {
    struct timeval tv{};
    if (gettimeofday(&tv, nullptr)) {
        return 0;
    }
    return (tv.tv_sec * 1000000ULL) + tv.tv_usec;
}

size_t strlcpy(char *dst, const char *src, size_t dstsize) {
    const size_t srclen = strlen(src);
    if (srclen < dstsize) {
        memcpy(dst, src, srclen + 1);
    } else if (dstsize != 0) {
        memcpy(dst, src, dstsize - 1);
        dst[dstsize - 1] = '\0';
    }
    return srclen;
}

size_t strlcat(char *dst, const char *src, size_t dstsize) {
    const size_t srclen = strlen(src);
    const size_t dstlen = strnlen(dst, dstsize);
    if (dstlen == dstsize) {
        return dstsize + srclen;
    }
    if (srclen < dstsize - dstlen) {
        memcpy(dst + dstlen, src, srclen + 1);
    } else {
        memcpy(dst + dstlen, src, dstsize - dstlen - 1);
        dst[dstsize - 1] = '\0';
    }
    return dstlen + srclen;
}

// https://github.com/apple/darwin-xnu/blob/master/libkern/gen/OSAtomicOperations.c
int64_t OSAtomicAdd64(int64_t amount, volatile int64_t *address) {
    return atomic_fetch_add_explicit(
        (_Atomic int64_t *) (uintptr_t) address, amount, memory_order_relaxed
    );
}

int32_t OSAtomicIncrement32(volatile int32_t *address) {
    return atomic_fetch_add_explicit(
        (_Atomic int32_t *) address, 1, memory_order_relaxed
    );
}

void __assert_rtn(const char *, const char *, int, const char *) {
    exit(1);
}

// https://opensource.apple.com/source/Libc/Libc-1272.200.26/util/mkpath_np.c.auto.html
int mkpath_np(const char *path, mode_t omode) {
    char *apath = nullptr;
    char *opath = nullptr;
    auto guard = std::shared_ptr<int>(new int(errno), [&](const int *error) {
        free(apath);
        free(opath);
        errno = *error;
    });

    if (0 == mkdir(path, omode)) {
        return 0;
    }

    struct stat sbuf{};
    switch (errno) {
        case ENOENT:
            break;
        case EEXIST:
            if (stat(path, &sbuf) == 0) {
                if (S_ISDIR(sbuf.st_mode)) {
                    return EEXIST;
                } else {
                    return ENOTDIR;
                }
            } else {
                return EIO;
            }
        case EISDIR:
            return EEXIST;
        default: {
            return errno;
        }
    }

    apath = strdup(path);
    if (apath == nullptr) {
        return ENOMEM;
    }

    mode_t chmod_mode = 0;
    char *s, *sn, *sl;
    sl = s = apath + strlen(apath) - 1;
    do {
        sn = s;
        if (s - 1 > apath && *s == '.' && *(s - 1) == '/') {
            s -= 2;
        }
        if (s > apath && *s == '/') {
            s--;
        }
    } while (s < sn);
    if (s < sl) {
        s[1] = '\0';
        path = opath = strdup(apath);
        if (opath == nullptr) {
            return ENOMEM;
        }
    }

    if (0 == mkdir(path, omode)) {
        return 0;
    }

    unsigned int depth = 0;
    while (true) {
        s = strrchr(apath, '/');
        if (!s) {
            return ENOENT;
        }
        *s = '\0';
        depth++;

        if (0 == mkdir(apath, S_IRWXU | S_IRWXG | S_IRWXO)) {
            struct stat dirstat{};
            if (-1 == stat(apath, &dirstat)) {
                return ENOENT;
            }

            if ((dirstat.st_mode & (S_IWUSR | S_IXUSR)) != (S_IWUSR | S_IXUSR)) {
                chmod_mode = dirstat.st_mode | S_IWUSR | S_IXUSR;
                if (-1 == chmod(apath, chmod_mode)) {
                    return ENOENT;
                }
            }

            break;
        } else if (errno == EEXIST) {
            if (stat(apath, &sbuf) == 0 &&
                S_ISDIR(sbuf.st_mode)) {

                break;
            }

            return ENOTDIR;
        } else if (errno != ENOENT) {
            return errno;
        }
    }

    while (depth > 1) {
        s = strrchr(apath, '\0');
        *s = '/';
        depth--;

        if (-1 == mkdir(apath, S_IRWXU | S_IRWXG | S_IRWXO)) {
            if (errno == EEXIST) {
                continue;
            }
            return errno;
        }

        if (chmod_mode) {
            if (-1 == chmod(apath, chmod_mode)) {
                return ENOENT;
            }
        }
    }

    if (-1 == mkdir(path, omode)) {
        if (errno == EEXIST && stat(path, &sbuf) == 0 && !S_ISDIR(sbuf.st_mode)) {
            return ENOTDIR;
        }
        return errno;
    }
    return 0;
}
