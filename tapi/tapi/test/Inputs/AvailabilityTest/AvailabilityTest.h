#import <Foundation/Foundation.h>

// Test public global.
extern int publicGlobalVariable NS_AVAILABLE(NA, NA);

// Test public ObjC class
NS_CLASS_AVAILABLE(NA, NA)
@interface Foo : NSObject
@end

// Test unavalable attribute.
#ifdef __i386__
#define UNAVAILABLE_I386 __attribute__((unavailable))
#else
#define UNAVAILABLE_I386
#endif
extern int publicGlobalVariable2 UNAVAILABLE_I386;

extern int publicGlobalVariable3 __attribute__((unavailable))
__attribute__((availability(macosx, introduced = 10.9)));
