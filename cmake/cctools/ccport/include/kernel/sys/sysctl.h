#ifndef CCPORT_SYS_SYSCTL_H_
#define CCPORT_SYS_SYSCTL_H_

#ifdef HAVE_SYS_SYSCTL_H
#include_next <sys/sysctl.h>
#else
#include <stddef.h>

extern int sysctl(
    int *name,
    int nlen,
    void *oldval,
    size_t *oldlenp,
    void *newval,
    size_t newlen
);
#endif /* HAVE_SYS_SYSCTL_H */

#ifndef CTL_KERN
#define CTL_KERN 1
#endif /* CTL_KERN */

#ifndef KERN_OSRELEASE
#define KERN_OSRELEASE 2
#endif /* KERN_OSRELEASE */

#endif /* CCPORT_SYS_SYSCTL_H_ */
