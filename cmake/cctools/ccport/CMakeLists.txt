cmake_minimum_required(VERSION 3.0)

project(ccport)

set(CMAKE_C_STANDARD 99)

include(CcDetectTarget)
cc_detect_target(CC)

include(CcChecks)
cc_check_headers(
    sys/_types.h
    sys/sysctl.h
)
cc_check_funcs(strmode)

include(TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
    add_definitions(-D__BIG_ENDIAN__=1)
else()
    add_definitions(-D__LITTLE_ENDIAN__=1)
endif()
add_definitions(-D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS)

if(CC_ARCH_X86_64)
    add_definitions(-DEMULATED_HOST_CPU_TYPE=16777223)
    add_definitions(-DEMULATED_HOST_CPU_SUBTYPE=3)
elseif(CC_ARCH_X86)
    add_definitions(-DEMULATED_HOST_CPU_TYPE=7)
    add_definitions(-DEMULATED_HOST_CPU_SUBTYPE=10)
endif()

include_directories(
    include/ccport
    include/kernel
    include/external
    ${CCTOOLS_ROOT}/include
    $<TARGET_PROPERTY:uuid,INCLUDE_DIRECTORIES>
)

add_library(ccport ccport.c)
target_link_libraries(ccport uuid)

get_directory_property(CCPORT_DEFINITIONS COMPILE_DEFINITIONS)
target_compile_definitions(ccport PUBLIC ${CCPORT_DEFINITIONS})
