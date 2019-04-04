#ifndef CCPORT_STRING_H_
#define CCPORT_STRING_H_

#include_next <string.h>

#ifndef HAVE_STRMODE
#include <fcntl.h>

#define strmode ccport_strmode

__BEGIN_DECLS

/* https://www.freebsd.org/cgi/man.cgi?query=strmode */
extern void strmode(mode_t mode, char *bp);

__END_DECLS
#endif /* HAVE_STRMODE */

#endif /* CCPORT_STRING_H_ */
