file(GLOB_RECURSE LD64_SRCS ${LD64_ROOT}/src/ld/*.c ${LD64_ROOT}/src/ld/*.cpp)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

include(CcChecks)

cc_check_compile_flag(-Wno-cast-qual)
cc_check_compile_flag(-Wno-covered-switch-default)
cc_check_compile_flag(-Wno-date-time)
cc_check_compile_flag(-Wno-format)
cc_check_compile_flag(-Wno-format-pedantic)
cc_check_compile_flag(-Wno-gnu-include-next)
cc_check_compile_flag(-Wno-ignored-qualifiers)
cc_check_compile_flag(-Wno-implicit-fallthrough)
cc_check_compile_flag(-Wno-import-preprocessor-directive-pedantic)
cc_check_compile_flag(-Wno-non-virtual-dtor)
cc_check_compile_flag(-Wno-parentheses-equality)
cc_check_compile_flag(-Wno-pointer-arith)
cc_check_compile_flag(-Wno-vla-extension)
cc_check_compile_flag(-Wno-zero-length-array)

include_directories(
    include
    ${LD64_ROOT}/src/abstraction
    ${LD64_ROOT}/src/ld/parsers
    ${LD64_ROOT}/src/ld
    $<TARGET_PROPERTY:ccport,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:tapi,INCLUDE_DIRECTORIES>
)
set_directory_properties(
    PROPERTIES COMPILE_DEFINITIONS
    $<TARGET_PROPERTY:ccport,PUBLIC_COMPILE_DEFINITIONS>
)
add_compile_options(-fblocks)
add_definitions(-D__DARWIN_UNIX03=1)

option(LD64_LTO_STATIC "Link LTO statically." ON)

if(LD64_LTO_STATIC)
    foreach(target ${LLVM_TARGETS_TO_BUILD})
        list(
            APPEND LD64_EXTRA_DEPENDS
            LLVM${target}Desc
            LLVM${target}CodeGen
            LLVM${target}AsmParser
            LLVM${target}Disassembler
        )
    endforeach()
    aux_source_directory(${LLVM_MAIN_SRC_DIR}/tools/lto LD64_EXTRA_SRCS)
else()
    set(LD64_EXTRA_DEPENDS LTO)
endif()

add_llvm_tool(
    ld64 ${LD64_SRCS} ldport.cpp ${LD64_EXTRA_SRCS}
    DEPENDS tapi ${LD64_EXTRA_DEPENDS} LLVMLTO LLVMSupport LLVMBinaryFormat LLVMObject clangBasic
)
target_link_libraries(
    ld64 PRIVATE
    ccport
    objc2
    tapi
    ${LD64_EXTRA_DEPENDS}
    LLVMTarget
    LLVMLTO
    LLVMSupport
    LLVMBinaryFormat
    LLVMObject
    clangBasic
    dl
    xar
    xml2
    ssl
    crypto
    zlibstatic
)
