option(LIBRESSL_ROOT "Source directory of libressl")
if(NOT LIBRESSL_ROOT)
    set(LIBRESSL_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../libressl")
endif()

add_subdirectory(${LIBRESSL_ROOT} libressl)
