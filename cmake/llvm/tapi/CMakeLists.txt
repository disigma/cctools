include(CcChecks)

cc_check_compile_flag(-Wno-gnu-include-next)
cc_check_compile_flag(-Wno-nested-anon-types)
cc_check_compile_flag(-Wno-delete-non-virtual-dtor)

include_directories(include)
include_directories("${TAPI_ROOT}/include")
include_directories($<TARGET_PROPERTY:clangBasic,INCLUDE_DIRECTORIES>)

aux_source_directory(${TAPI_ROOT}/lib/Core TAPI_CORE_SOURCES)
aux_source_directory(${TAPI_ROOT}/tools/libtapi LIBTAPI_SOURCES)
llvm_add_library(tapi ${TAPI_CORE_SOURCES} ${LIBTAPI_SOURCES} DEPENDS LLVMSupport clangBasic)
