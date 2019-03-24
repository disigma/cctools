#ifndef CCPORT_MACH_VM_MAP_H_
#define CCPORT_MACH_VM_MAP_H_

#include <mach/mach_vm.h>

/* https://developer.apple.com/documentation/kernel/1402429-mach_vm_machine_attribute */
kern_return_t vm_machine_attribute(
    vm_map_t target_task,
    vm_address_t address,
    vm_size_t size,
    vm_machine_attribute_t attribute,
    vm_machine_attribute_val_t *value
);

#endif /* CCPORT_MACH_VM_MAP_H_ */