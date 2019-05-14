option(ZLIB_ROOT "Source directory of zlib")
if(NOT ZLIB_ROOT)
    set(ZLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../zlib")
endif()

add_subdirectory(${ZLIB_ROOT} zlib)
