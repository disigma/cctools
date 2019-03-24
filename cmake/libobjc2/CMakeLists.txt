cmake_minimum_required(VERSION 3.0)

project(libobjc2)

enable_language(ASM)

option(OBJC2_ROOT "Source directory of libobjc2")

if(NOT OBJC2_ROOT)
    set(OBJC2_ROOT "../../libobjc2")
endif()

include_directories(objc2 ${OBJC2_ROOT})

set(CMAKE_C_STANDARD 99)

include(CcChecks)
cc_check_compile_flag(-fexceptions)

add_definitions(
    -DGNUSTEP
    -D__OBJC_RUNTIME_INTERNAL__=1
    -D_XOPEN_SOURCE=700
    -D__BSD_VISIBLE=1
    -D_BSD_SOURCE=1
)
add_definitions(-DNO_SELECTOR_MISMATCH_WARNINGS)
add_definitions(-DTYPE_DEPENDENT_DISPATCH)

set(
    OBJC2_C_SOURCES
    abi_version.c
    alias_table.c
    block_to_imp.c
    caps.c
    category_loader.c
    class_table.c
    dtable.c
    eh_personality.c
    encoding2.c
    gc_none.c
    hash_table.c
    hooks.c
    ivar.c
    legacy_malloc.c
    loader.c
    protocol.c
    runtime.c
    sarray2.c
    selector_table.c
    sendmsg2.c
    statics_loader.c
    toydispatch.c
)
set(
    OBJC2_OBJC_SOURCES
    NSBlocks.m
    Protocol2.m
    arc.m
    associate.m
    blocks_runtime.m
    mutation.m
    properties.m
)
set(
    OBJC2_ASM_SOURCES
    block_trampolines.S
    objc_msgSend.S
)

include(CcLocateSources)
cc_locate_sources(
    OBJC2_SOURCES ${OBJC2_ROOT}
    ${OBJC2_C_SOURCES} ${OBJC2_OBJC_SOURCES} ${OBJC2_ASM_SOURCES}
)

add_library(objc2 ${OBJC2_SOURCES})
