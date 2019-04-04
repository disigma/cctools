#ifndef CCPORT_SYS_ATTR_H_
#define CCPORT_SYS_ATTR_H_

#include <sys/types.h>

/* https://developer.apple.com/documentation/kernel/attrgroup_t */
typedef u_int32_t attrgroup_t;

/* https://developer.apple.com/documentation/kernel/attrlist */
struct attrlist {
    u_short bitmapcount;
    u_int16_t reserved;
    attrgroup_t commonattr;
    attrgroup_t volattr;
    attrgroup_t dirattr;
    attrgroup_t fileattr;
    attrgroup_t forkattr;
};

#define ATTR_CMN_FNDRINFO 0x00004000

#define ATTR_FILE_DATALENGTH 0x00000200
#define ATTR_FILE_RSRCLENGTH 0x00001000

__BEGIN_DECLS

/* https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man2/getattrlist.2.html */
int getattrlist(
    const char* path,
    struct attrlist *attrList,
    void *attrBuf,
    size_t attrBufSize,
    unsigned long options
);

__END_DECLS

#endif /* CCPORT_SYS_ATTR_H_ */