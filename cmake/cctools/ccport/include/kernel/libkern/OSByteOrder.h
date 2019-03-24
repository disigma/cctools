#ifndef CCPORT_LIBKERN_OSBYTEORDER_H_
#define CCPORT_LIBKERN_OSBYTEORDER_H_

#include <stdint.h>

#define __DARWIN_OSSwapConstInt16(x) \
    ((__uint16_t)((((__uint16_t)(x) & 0xff00) >> 8) | \
                (((__uint16_t)(x) & 0x00ff) << 8)))

#define __DARWIN_OSSwapConstInt32(x) \
    ((__uint32_t)((((__uint32_t)(x) & 0xff000000) >> 24) | \
                (((__uint32_t)(x) & 0x00ff0000) >>  8) | \
                (((__uint32_t)(x) & 0x0000ff00) <<  8) | \
                (((__uint32_t)(x) & 0x000000ff) << 24)))

#define __DARWIN_OSSwapConstInt64(x) \
    ((__uint64_t)((((__uint64_t)(x) & 0xff00000000000000ULL) >> 56) | \
                (((__uint64_t)(x) & 0x00ff000000000000ULL) >> 40) | \
                (((__uint64_t)(x) & 0x0000ff0000000000ULL) >> 24) | \
                (((__uint64_t)(x) & 0x000000ff00000000ULL) >>  8) | \
                (((__uint64_t)(x) & 0x00000000ff000000ULL) <<  8) | \
                (((__uint64_t)(x) & 0x0000000000ff0000ULL) << 24) | \
                (((__uint64_t)(x) & 0x000000000000ff00ULL) << 40) | \
                (((__uint64_t)(x) & 0x00000000000000ffULL) << 56)))

static inline uint16_t OSSwapInt16(uint16_t data) {
    return __DARWIN_OSSwapConstInt16(data);
}

static inline uint32_t OSSwapInt32(uint32_t data) {
    return __DARWIN_OSSwapConstInt32(data);
}

static inline uint64_t OSSwapInt64(uint64_t data) {
    return __DARWIN_OSSwapConstInt64(data);
}

#endif /* CCPORT_LIBKERN_OSBYTEORDER_H_ */
