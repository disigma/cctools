#ifndef CCPORT_MACH_ARM__STRUCTS_H_
#define CCPORT_MACH_ARM__STRUCTS_H_

#include <stdint.h>

#ifndef __uint8_t
#define ccport_uint8_t_defined
#define __uint8_t uint8_t
#endif /* __uint8_t */

#ifndef __uint16_t
#define ccport_uint16_t_defined
#define __uint16_t uint16_t
#endif /* __uint16_t */

#ifndef __uint32_t
#define ccport_uint32_t_defined
#define __uint32_t uint32_t
#endif /* __uint32_t */

#ifndef __uint64_t
#define ccport_uint64_t_defined
#define __uint64_t uint64_t
#endif /* __uint64_t */

#include_next <mach/arm/_structs.h>

#ifdef ccport_uint8_t_defined
#undef ccport_uint8_t_defined
#undef __uint8_t
#endif /* ccport_uint8_t_defined */

#ifdef ccport_uint16_t_defined
#undef ccport_uint16_t_defined
#undef __uint16_t
#endif /* ccport_uint16_t_defined */

#ifdef ccport_uint32_t_defined
#undef ccport_uint32_t_defined
#undef __uint32_t
#endif /* ccport_uint32_t_defined */

#ifdef ccport_uint64_t_defined
#undef ccport_uint64_t_defined
#undef __uint64_t
#endif /* ccport_uint64_t_defined */

#endif /* CCPORT_MACH_ARM__STRUCTS_H_ */
