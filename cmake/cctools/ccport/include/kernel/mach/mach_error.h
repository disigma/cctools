#ifndef	CCPORT_MACH_MACH_ERROR_H_
#define	CCPORT_MACH_MACH_ERROR_H_

#include <mach/error.h>

/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/libsyscall/mach/mach/mach_error.h#L70 */
char *mach_error_string(mach_error_t error_value);

#endif /* CCPORT_MACH_MACH_ERROR_H_ */

