#ifndef CCPORT_MACH_MACH_INIT_H_
#define CCPORT_MACH_MACH_INIT_H_

#include <mach/mach_types.h>
#include <mach/vm_page_size.h>

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/mach_task_self.html */
mach_port_t mach_task_self(void);

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/mach_host_self.html */
host_name_port_t mach_host_self(void);

#endif /* CCPORT_MACH_MACH_INIT_H_ */