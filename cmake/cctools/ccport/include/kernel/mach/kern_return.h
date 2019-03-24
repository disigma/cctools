#ifndef CCPORT_MACH_KERN_RETURN_H_
#define CCPORT_MACH_KERN_RETURN_H_

/* https://developer.apple.com/documentation/kernel/kern_return_t */
typedef int kern_return_t;

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/osfmk/mach/kern_return.h#L72 */
#define KERN_SUCCESS 0
#define KERN_FAILURE 5

#endif /* CCPORT_MACH_KERN_RETURN_H_ */
