#ifndef CCPORT_MACH_MACH_HOST_H_
#define CCPORT_MACH_MACH_HOST_H_

#include <mach/host_info.h>
#include <mach/kern_return.h>

/* https://developer.apple.com/documentation/kernel/1502514-host_info */
/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/host_info.html */
extern kern_return_t host_info(
    host_t host,
    host_flavor_t flavor,
    host_info_t host_info_out,
    mach_msg_type_number_t *host_info_outCnt
);

#endif /* CCPORT_MACH_MACH_HOST_H_ */