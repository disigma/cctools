#ifndef LD64_UNISTD_H_
#define LD64_UNISTD_H_

#include_next <unistd.h>
#include <fcntl.h>

// http://www.manpagez.com/man/3/mkpath_np/
int mkpath_np(const char *path, mode_t omode);

// Fix missing include in ld64/src/ld/code-sign-blobs/blob.cpp
#include <string.h>

#endif // LD64_UNISTD_H_