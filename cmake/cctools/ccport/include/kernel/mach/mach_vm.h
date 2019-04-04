#ifndef CCPORT_MACH_MACH_VM_H_
#define CCPORT_MACH_MACH_VM_H_

#include <mach/kern_return.h>
#include <mach/port.h>
#include <mach/vm_attributes.h>
#include <mach/vm_types.h>

/* https://developer.apple.com/documentation/kernel/vm_map_t */
typedef mach_port_t vm_map_t;

__BEGIN_DECLS

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/vm_allocate.html */
/* https://developer.apple.com/documentation/kernel/1585381-vm_allocate */
kern_return_t vm_allocate(
    vm_map_t target_task,
    vm_address_t *address,
    vm_size_t size,
    int flags
);

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/vm_deallocate.html */
/* https://developer.apple.com/documentation/kernel/1585284-vm_deallocate */
kern_return_t vm_deallocate(
    vm_map_t target_task,
    vm_address_t address,
    vm_size_t size
);

__END_DECLS

#endif /* CCPORT_MACH_MACH_VM_H_ */