cmake_minimum_required(VERSION 3.0)

project(ccport)

include(CcDetectTarget)

set(CMAKE_C_STANDARD 99)

cc_detect_target(CC)

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
)

add_library(ccport ccport.c)

get_directory_property(CCPORT_DEFINITIONS COMPILE_DEFINITIONS)
get_directory_property(CCPORT_COMPILE_OPTIONS COMPILE_OPTIONS)

target_compile_definitions(ccport PUBLIC ${CCPORT_DEFINITIONS})
target_compile_options(ccport PUBLIC ${CCPORT_COMPILE_OPTIONS})
