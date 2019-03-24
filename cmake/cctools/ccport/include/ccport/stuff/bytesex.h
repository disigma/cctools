#ifndef CCPORT_STUFF_BYTESEX_H_
#define CCPORT_STUFF_BYTESEX_H_

#define __darwin_i386_float_state i386_float_state

#include_next <stuff/bytesex.h>

#ifndef _STUFF_ARCH_H_
/* Fix broken includes of ld.h */
#include <stuff/arch.h>
#endif
#include <stuff/macosx_deployment_target.h>

#ifndef SWAP_LONG
#define SWAP_LONG(a) (((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned long)(a) >> 24))
#endif

#endif /* CCPORT_STUFF_BYTESEX_H_ */
