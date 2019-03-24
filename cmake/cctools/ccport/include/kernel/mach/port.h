#ifndef	CCPORT_MACH_PORT_H_
#define CCPORT_MACH_PORT_H_

#include <mach/vm_types.h>

/* https://developer.apple.com/documentation/kernel/ipc_port_t */
typedef struct ipc_port	*ipc_port_t;

/* https://developer.apple.com/documentation/kernel/mach_port_t */
typedef ipc_port_t mach_port_t;

/* https://developer.apple.com/documentation/kernel/mach_port_name_t */
typedef natural_t mach_port_name_t;

/* https://developer.apple.com/documentation/kernel/mach_port_type_t */
typedef natural_t mach_port_type_t;

/* https://developer.apple.com/documentation/kernel/ipc_space_t */
typedef mach_port_t ipc_space_t;

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/mach_msg.html */
#define MACH_PORT_NULL ((mach_port_t) 0)

#endif /* CCPORT_MACH_PORT_H_ */
