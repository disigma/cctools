#ifndef CCPORT_MACH_THREAD_H_
#define CCPORT_MACH_THREAD_H_

/* https://developer.apple.com/documentation/kernel/thread_t */
typedef struct thread *thread_t;

/* https://developer.apple.com/documentation/kernel/thread_port_t */
typedef thread_t thread_port_t;

#endif /* CCPORT_MACH_THREAD_H_ */
