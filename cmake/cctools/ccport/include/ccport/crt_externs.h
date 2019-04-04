/* https://opensource.apple.com/source/Libc/Libc-1272.200.26/include/crt_externs.h.auto.html */
#ifndef CCPORT_CRT_EXTERNS_H_
#define CCPORT_CRT_EXTERNS_H_

#include <mach-o/loader.h>

__BEGIN_DECLS

#ifdef __LP64__
extern struct mach_header_64 *
#else
extern struct mach_header *
#endif /* __LP64__ */

_NSGetMachExecuteHeader(void);

__END_DECLS

#endif /* CCPORT_CRT_EXTERNS_H_ */
