#ifndef CCPORT_ERRNO_H_
#define CCPORT_ERRNO_H_

#include_next <errno.h>

#ifndef EBADRPC
#define EBADRPC 72
#endif /* EBADRPC */

#ifndef EFTYPE
#define	EFTYPE 79
#endif /* EFTYPE */

#endif /* CCPORT_ERRNO_H_ */
