#ifndef CCPORT_STRING_H_
#define CCPORT_STRING_H_

#include_next <string.h>

#include <fcntl.h>

/* https://www.freebsd.org/cgi/man.cgi?query=strmode */
extern void strmode(mode_t mode, char *bp);

#endif /* CCPORT_STRING_H_ */
