#ifndef LD64_LIBKERN_OSBYTEORDER_H_
#define LD64_LIBKERN_OSBYTEORDER_H_

/* https://github.com/apple/darwin-xnu/blob/master/libkern/libkern/OSByteOrder.h */
/* https://github.com/apple/darwin-xnu/blob/master/libkern/libkern/machine/OSByteOrder.h */
#include_next <libkern/OSByteOrder.h>

static inline uint16_t OSReadInt16(
    const volatile void *base,
    uintptr_t byteOffset
) {
    return *(volatile uint16_t *) ((uintptr_t) base + byteOffset);
}

static inline uint32_t OSReadInt32(
    const volatile void *base,
    uintptr_t byteOffset
) {
    return *(volatile uint32_t *) ((uintptr_t) base + byteOffset);
}

static inline uint64_t OSReadInt64(
    const volatile void *base,
    uintptr_t byteOffset
) {
    return *(volatile uint64_t *) ((uintptr_t) base + byteOffset);
}

static inline uint16_t OSReadSwapInt16(
    const volatile void *base,
    uintptr_t byteOffset
) {
    uint16_t data = *(volatile uint16_t *) ((uintptr_t) base + byteOffset);
    return OSSwapInt16(data);
}

static inline uint32_t OSReadSwapInt32(
    const volatile void *base,
    uintptr_t byteOffset
) {
    uint32_t data = *(volatile uint32_t *) ((uintptr_t) base + byteOffset);
    return OSSwapInt32(data);
}

static inline uint64_t OSReadSwapInt64(
    const volatile void *base,
    uintptr_t byteOffset
) {
    uint64_t data = *(volatile uint64_t *) ((uintptr_t) base + byteOffset);
    return OSSwapInt64(data);
}

static inline void OSWriteInt16(
    volatile void *base,
    uintptr_t byteOffset,
    uint16_t data
) {
    *(volatile uint16_t *) ((uintptr_t) base + byteOffset) = data;
}

static inline void OSWriteInt32(
    volatile void *base,
    uintptr_t byteOffset,
    uint32_t data
) {
    *(volatile uint32_t *) ((uintptr_t) base + byteOffset) = data;
}

static inline void OSWriteInt64(
    volatile void *base,
    uintptr_t byteOffset,
    uint64_t data
) {
    *(volatile uint64_t *) ((uintptr_t) base + byteOffset) = data;
}

static inline void OSWriteSwapInt16(
    volatile void *base,
    uintptr_t byteOffset,
    uint16_t data
) {
    *(volatile uint16_t *) ((uintptr_t) base + byteOffset) = OSSwapInt16(data);
}

static inline void OSWriteSwapInt32(
    volatile void *base,
    uintptr_t byteOffset,
    uint32_t data
) {
    *(volatile uint32_t *) ((uintptr_t) base + byteOffset) = OSSwapInt32(data);
}

static inline void OSWriteSwapInt64(
    volatile void *base,
    uintptr_t byteOffset,
    uint64_t data
) {
    *(volatile uint64_t *) ((uintptr_t) base + byteOffset) = OSSwapInt64(data);
}

#if defined(__LITTLE_ENDIAN__)
#define OSReadBigInt16 OSReadSwapInt16
#define OSReadBigInt32 OSReadSwapInt32
#define OSReadBigInt64 OSReadSwapInt64
#define OSWriteBigInt16 OSWriteSwapInt16
#define OSWriteBigInt32 OSWriteSwapInt32
#define OSWriteBigInt64 OSWriteSwapInt64

#define OSReadLittleInt16 OSReadInt16
#define OSReadLittleInt32 OSReadInt32
#define OSReadLittleInt64 OSReadInt64
#define OSWriteLittleInt16 OSWriteInt16
#define OSWriteLittleInt32 OSWriteInt32
#define OSWriteLittleInt64 OSWriteInt64

#define OSSwapBigToHostInt32(x) OSSwapInt32(x)
#define OSSwapBigToHostInt64(x) OSSwapInt64(x)

#define OSSwapHostToBigInt64(x) OSSwapInt64(x)

#elif defined(__BIG_ENDIAN__)

#define OSReadBigInt16 OSReadInt16
#define OSReadBigInt32 OSReadInt32
#define OSReadBigInt64 OSReadInt64
#define OSWriteBigInt16 OSWriteInt16
#define OSWriteBigInt32 OSWriteInt32
#define OSWriteBigInt64 OSWriteInt64

#define OSReadLittleInt16 OSReadSwapInt16
#define OSReadLittleInt32 OSReadSwapInt32
#define OSReadLittleInt64 OSReadSwapInt64
#define OSWriteLittleInt16 OSWriteSwapInt16
#define OSWriteLittleInt32 OSWriteSwapInt32
#define OSWriteLittleInt64 OSWriteSwapInt64

#define OSSwapBigToHostInt32(x) ((uint32_t)(x))
#define OSSwapBigToHostInt64(x) ((uint64_t)(x))

#define OSSwapHostToBigInt64(x) ((uint64_t)(x))
#else
#error Unknown endianess.
#endif

#endif // LD64_LIBKERN_OSBYTEORDER_H_
