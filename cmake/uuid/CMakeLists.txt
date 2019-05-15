cmake_minimum_required(VERSION 3.0)

project(uuid)

set(CMAKE_C_STANDARD 99)

option(UUID_ROOT "Source directory of uuid")
if(NOT UUID_ROOT)
    set(UUID_ROOT "../../uuid")
endif()

include(CcChecks)
cc_check_headers(
    fcntl.h
    inttypes.h
    limits.h
    netinet/in.h
    stdlib.h
    string.h
    sys/file.h
    sys/ioctl.h
    sys/socket.h
    sys/time.h
    unistd.h
)

cc_check_funcs(ftruncate gettimeofday memset socket strtoul usleep srandom)

include(CcLocateSources)
cc_locate_sources(
    UUID_SOURCES ${UUID_ROOT}
    clear.c
    compare.c
    copy.c
    gen_uuid.c
    isnull.c
    pack.c
    parse.c
    unpack.c
    unparse.c
    uuid_time.c
    randutils.c
)

include_directories(${UUID_ROOT})
add_library(uuid ${UUID_SOURCES})
