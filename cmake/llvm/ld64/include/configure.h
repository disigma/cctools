#ifndef LD64_CONFIGURE_H_
#define LD64_CONFIGURE_H_

#include <sys/param.h>
#include <limits.h>
#include <unistd.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#define SUPPORT_ARCH_armv6 1
#define SUPPORT_ARCH_armv7 1
#define SUPPORT_ARCH_armv7s 1
#define SUPPORT_ARCH_arm64 1
#define SUPPORT_ARCH_i386 1
#define SUPPORT_ARCH_x86_64 1
#define SUPPORT_ARCH_x86_64h 1
#define SUPPORT_ARCH_armv6m 1
#define SUPPORT_ARCH_armv7k 1
#define SUPPORT_ARCH_armv7m 1
#define SUPPORT_ARCH_armv7em 1

#define ALL_SUPPORTED_ARCHS "i386 x86_64 x86_64h armv6 armv7 armv7s armv7m armv7k arm64"

#define LD64_VERSION_NUM 0

#define BITCODE_XAR_VERSION "1.0"

#define CPU_TYPE_X86 CPU_TYPE_I386
#define CPU_SUBTYPE_ARM64_E CPU_SUBTYPE_ARM64E
#define CPU_SUBTYPE_X86_ALL CPU_SUBTYPE_I386_ALL

#ifndef HW_NCPU
#define HW_NCPU 3
#endif

#ifndef CTL_HW
#define CTL_HW  6
#endif

#ifndef ARG_MAX
#define ARG_MAX 31072
#endif

// https://developer.apple.com/documentation/kernel/uuid_string_t
// https://opensource.apple.com/source/xnu/xnu-4570.41.2/bsd/sys/_types.h.auto.html
typedef	char uuid_string_t[37];

#define dl_info Dl_info

#ifdef __cplusplus
// Fix missing includes
#include <algorithm>
#include <mutex>
#endif // __cplusplus

#endif // LD64_CONFIGURE_H_
