#ifndef CCPORT_OBJC_OBJC_RUNTIME_H_
#define CCPORT_OBJC_OBJC_RUNTIME_H_

#include <objc/runtime.h>

#define CLS_GETINFO(cls,infomask) ((cls)->info & (infomask))

#define CLS_CLASS 0x1L
#define CLS_META 0x2L

#endif /* CCPORT_OBJC_OBJC_RUNTIME_H_ */
