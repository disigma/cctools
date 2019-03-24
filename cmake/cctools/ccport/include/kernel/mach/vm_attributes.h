#ifndef CCPORT_MACH_VM_ATTRIBUTES_H_
#define CCPORT_MACH_VM_ATTRIBUTES_H_

/* https://developer.apple.com/documentation/kernel/vm_machine_attribute_t */
typedef unsigned int vm_machine_attribute_t;

/* https://developer.apple.com/documentation/kernel/vm_machine_attribute_val_t */
typedef int vm_machine_attribute_val_t;

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/vm_machine_attribute.html */
#define	MATTR_CACHE 1
#define MATTR_VAL_ICACHE_FLUSH 8

#endif /* CCPORT_MACH_VM_ATTRIBUTES_H_ */