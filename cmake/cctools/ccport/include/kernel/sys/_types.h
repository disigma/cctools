#ifndef CCPORT_SYS__TYPES_H_
#define CCPORT_SYS__TYPES_H_

#ifdef HAVE_SYS__TYPES_H
#include_next <sys/_types.h>
#endif /* HAVE_SYS__TYPES_H */

typedef unsigned int __darwin_natural_t;

typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;

#endif /* CCPORT_SYS__TYPES_H_ */
