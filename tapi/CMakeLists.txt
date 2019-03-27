cmake_minimum_required(VERSION 3.0)

include_directories($<TARGET_PROPERTY:clangBasic,INCLUDE_DIRECTORIES>)

include_directories(port)
include_directories(swift/lib/TBDGen)

aux_source_directory(swift/lib/TBDGen/tapi SWIFT_TAPI_SOURCES)
set(TAPI_SOURCES tapi/tools/libtapi/LinkerInterfaceFile.cpp)
llvm_add_library(
    tapi ${SWIFT_TAPI_SOURCES} ${TAPI_SOURCES}
    DEPENDS LLVMSupport LLVMBinaryFormat clangBasic
)

set(
    TAPI_RUN_SOURCES
    tapi/tools/tapi-run/tapi-run.cpp
    tapi/lib/Core/FileSystem.cpp
)

add_llvm_utility(tapi-run ${TAPI_RUN_SOURCES} DEPENDS tapi)
target_link_libraries(tapi-run PRIVATE tapi LLVMSupport LLVMBinaryFormat)
