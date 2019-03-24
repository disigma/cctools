cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 99)

include(TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
    add_definitions(-D__BIG_ENDIAN__=1)
else()
    add_definitions(-D__LITTLE_ENDIAN__=1)
endif()

add_definitions(-D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS)

include(CcChecks)
cc_check_compile_flag(-Wno-format)
cc_check_compile_flag(-Wno-incompatible-pointer-types)
cc_check_compile_flag(-Wno-int-conversion)
cc_check_compile_flag(-Wno-deprecated-declarations)
cc_check_compile_flag(-Wno-deprecated)
cc_check_compile_flag(-Wno-attributes)

cc_check_headers(sys/_types.h sys/sysctl.h)
