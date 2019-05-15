cmake_minimum_required(VERSION 3.0)

project(cctools)

set(CMAKE_C_STANDARD 99)

option(CCTOOLS_ROOT "Source directory of cctools")
if(NOT CCTOOLS_ROOT)
    set(CCTOOLS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../cctools")
endif()

# CCPORT
add_subdirectory(ccport)
set_directory_properties(
    PROPERTIES
    INCLUDE_DIRECTORIES $<TARGET_PROPERTY:ccport,INCLUDE_DIRECTORIES>
    COMPILE_DEFINITIONS $<TARGET_PROPERTY:ccport,PUBLIC_COMPILE_DEFINITIONS>
)
add_compile_options(-include config.h)

# Check and set compile flags
include(CcChecks)
cc_check_compile_flag(-Wno-attributes)
cc_check_compile_flag(-Wno-deprecated)
cc_check_compile_flag(-Wno-deprecated-declarations)
cc_check_compile_flag(-Wno-format)
cc_check_compile_flag(-Wno-gnu-include-next)
cc_check_compile_flag(-Wno-implicit-function-declaration)
cc_check_compile_flag(-Wno-incompatible-pointer-types)
cc_check_compile_flag(-Wno-int-conversion)
cc_check_compile_flag(-Wno-int-to-pointer-cast)

# Macro for adding executables
macro(cc_add_executable name)
    add_executable(${name} ${ARGN})
    list(APPEND CCTOOLS_TARGETS ${name})
endmacro()

# DEMANGLE
add_subdirectory(demangle)

# LIBSTUFF
aux_source_directory(${CCTOOLS_ROOT}/libstuff STUFF_SOURCES)
add_library(stuff ${STUFF_SOURCES})
target_link_libraries(stuff ccport)

# LIBMACHO
aux_source_directory(${CCTOOLS_ROOT}/libmacho MACHO_SOURCES)
add_library(macho ${MACHO_SOURCES})
target_link_libraries(macho stuff)
set_property(
    SOURCE ${CCTOOLS_ROOT}/libmacho/swap.c APPEND
    PROPERTY COMPILE_DEFINITIONS FALSE=0
)

# AR
aux_source_directory(${CCTOOLS_ROOT}/ar AR_SOURCES)
cc_add_executable(ar ${AR_SOURCES})
target_link_libraries(ar stuff)

# EFITOOLS
aux_source_directory(${CCTOOLS_ROOT}/efitools EFITOOLS_SOURCES)
foreach(source ${EFITOOLS_SOURCES})
    get_filename_component(target ${source} NAME_WE)
    cc_add_executable(${target} ${source})
    target_link_libraries(${target} stuff)
endforeach()

# GPROF
aux_source_directory(${CCTOOLS_ROOT}/gprof GPROF_SOURCES)
cc_add_executable(gprof ${GPROF_SOURCES})
target_link_libraries(gprof stuff)

# MISC
aux_source_directory(${CCTOOLS_ROOT}/misc MISC_SOURCES)
foreach(source ${MISC_SOURCES})
    get_filename_component(target ${source} NAME_WE)
    cc_add_executable(${target} ${source})
    target_link_libraries(${target} stuff)
endforeach()

# OTOOL
add_definitions(-DEFI_SUPPORT)
cc_check_compile_flag(-Wno-endif-labels)
aux_source_directory(${CCTOOLS_ROOT}/otool OTOOL_SOURCES)
cc_add_executable(otool ${OTOOL_SOURCES})
target_link_libraries(otool stuff objc2 dl demangle)
target_include_directories(
    otool PRIVATE
    ${CCTOOLS_ROOT}/otool
    $<TARGET_PROPERTY:objc2,INCLUDE_DIRECTORIES>
)

# LD
aux_source_directory(${CCTOOLS_ROOT}/ld LD_SOURCES)
cc_add_executable(ld ${LD_SOURCES})
target_link_libraries(ld stuff)

add_custom_target(cctools DEPENDS ${CCTOOLS_TARGETS})
