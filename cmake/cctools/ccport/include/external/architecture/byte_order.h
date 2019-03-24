#ifndef CCPORT_ARCHITECTURE_BYTE_ORDER_H_
#define CCPORT_ARCHITECTURE_BYTE_ORDER_H_

#include <libkern/OSByteOrder.h>

/* https://developer.apple.com/documentation/kernel/nxbyteorder */
/* https://github.com/apple/darwin-xnu/blob/xnu-4903.221.2/EXTERNAL_HEADERS/architecture/byte_order.h#L136 */
enum NXByteOrder {
    NX_UnknownByteOrder,
    NX_LittleEndian,
    NX_BigEndian
};

/* https://developer.apple.com/documentation/kernel/1517899-nxhostbyteorder */
enum NXByteOrder NXHostByteOrder(void);

#endif /* CCPORT_ARCHITECTURE_BYTE_ORDER_H_ */
