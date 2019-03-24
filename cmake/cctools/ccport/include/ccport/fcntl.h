#ifndef CCPORT_FCNTL_H_
#define CCPORT_FCNTL_H_

#include_next <fcntl.h>

#ifndef O_FSYNC
#define O_FSYNC O_SYNC
#endif

#endif /* CCPORT_FCNTL_H_ */
