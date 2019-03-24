#ifndef CCPORT_MACH_HOST_INFO_H_
#define CCPORT_MACH_HOST_INFO_H_

#include <mach/machine.h>
#include <mach/message.h>

/* https://developer.apple.com/documentation/kernel/host_info_t */
typedef integer_t *host_info_t;

/* http://web.mit.edu/darwin/src/modules/xnu/osfmk/man/host_info.html */
#define HOST_BASIC_INFO 1
#define HOST_SCHED_INFO 3

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/host_info.h#L130 */
#pragma pack(4)
struct host_basic_info {
    integer_t max_cpus;
    integer_t avail_cpus;
    natural_t memory_size;
    cpu_type_t cpu_type;
    cpu_subtype_t cpu_subtype;
    cpu_threadtype_t cpu_threadtype;
    integer_t physical_cpu;
    integer_t physical_cpu_max;
    integer_t logical_cpu;
    integer_t logical_cpu_max;
    uint64_t max_mem;
};
#pragma pack()

/* https://developer.apple.com/documentation/kernel/host_basic_info_data_t */
typedef struct host_basic_info host_basic_info_data_t;

/* https://developer.apple.com/documentation/kernel/host_basic_info_t */
typedef struct host_basic_info *host_basic_info_t;

/* https://www.gnu.org/software/hurd/gnumach-doc/Host-Information.html */
#define HOST_BASIC_INFO_COUNT ((mach_msg_type_number_t) (sizeof(host_basic_info_data_t) / sizeof(integer_t)))

/* https://developer.apple.com/documentation/kernel/host_sched_info_data_t */
struct host_sched_info {
    integer_t min_timeout;
    integer_t min_quantum;
};

/* https://developer.apple.com/documentation/kernel/host_sched_info_data_t */
typedef	struct host_sched_info host_sched_info_data_t;

#define HOST_SCHED_INFO_COUNT ((mach_msg_type_number_t) (sizeof(host_sched_info_data_t) / sizeof(integer_t)))

/* https://developer.apple.com/documentation/kernel/host_t */
typedef struct host *host_t;

/* https://developer.apple.com/documentation/kernel/host_flavor_t */
typedef integer_t host_flavor_t;

/* https://developer.apple.com/documentation/kernel/host_name_port_t */
typedef host_t host_name_port_t;

#endif /* CCPORT_MACH_HOST_INFO_H_ */
