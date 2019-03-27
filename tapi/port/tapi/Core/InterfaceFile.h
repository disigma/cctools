#ifndef PORT_TAPI_CORE_INTERFACEFILE_H_
#define PORT_TAPI_CORE_INTERFACEFILE_H_

#include <tapi/InterfaceFile.h>

TAPI_NAMESPACE_INTERNAL_BEGIN

class PortInterfaceFile : public InterfaceFile {
public:
    tapi::v1::Platform getPlatform() const {
        switch (InterfaceFile::getPlatform()) {
            case tapi::internal::Platform::macOS:
                return tapi::v1::Platform::OSX;
            case tapi::internal::Platform::iOS:
            case tapi::internal::Platform::iOSSimulator:
                return tapi::v1::Platform::iOS;
            case tapi::internal::Platform::tvOS:
            case tapi::internal::Platform::tvOSSimulator:
                return tapi::v1::Platform::tvOS;
            case tapi::internal::Platform::watchOS:
            case tapi::internal::Platform::watchOSSimulator:
                return tapi::v1::Platform::watchOS;
            case tapi::internal::Platform::bridgeOS:
                return tapi::v1::Platform::bridgeOS;
            case tapi::internal::Platform::unknown:
                return tapi::v1::Platform::Unknown;
        }
    }
};

TAPI_NAMESPACE_INTERNAL_END

#define InterfaceFile PortInterfaceFile

#endif // PORT_TAPI_CORE_INTERFACEFILE_H_