#ifndef CCPORT_MACH_MACH_PORT_H_
#define CCPORT_MACH_MACH_PORT_H_

#include <mach/kern_return.h>
#include <mach/port.h>

__BEGIN_DECLS

/* https://developer.apple.com/documentation/kernel/1578714-mach_port_type */
kern_return_t mach_port_type(
    ipc_space_t task,
    mach_port_name_t name,
    mach_port_type_t *ptype
);

/* https://developer.apple.com/documentation/kernel/1578777-mach_port_deallocate */
kern_return_t mach_port_deallocate(
    ipc_space_t task,
    mach_port_name_t name
);

__END_DECLS

#endif /* CCPORT_MACH_MACH_PORT_H_ */
