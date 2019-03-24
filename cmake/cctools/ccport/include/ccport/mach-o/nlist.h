#ifndef CCPORT_MACH_O_NLIST_H_
#define CCPORT_MACH_O_NLIST_H_

#include <stdint.h>

#ifdef __LP64__
#undef __LP64__
#include_next <mach-o/nlist.h>
#define __LP64__ 1
#else
#include_next <mach-o/nlist.h>
#endif /* __LP64__ */

#endif /* CCPORT_MACH_O_NLIST_H_ */
