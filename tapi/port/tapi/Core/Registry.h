#ifndef PORT_TAPI_CORE_REGISTRY_H_
#define PORT_TAPI_CORE_REGISTRY_H_

#include <tapi/Registry.h>

TAPI_NAMESPACE_INTERNAL_BEGIN

inline void Registry::addBinaryReaders() {
    //add(std::unique_ptr<Reader>(new MachODylibReader));
}

TAPI_NAMESPACE_INTERNAL_END

#endif // PORT_TAPI_CORE_REGISTRY_H_
