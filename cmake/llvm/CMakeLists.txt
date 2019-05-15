cmake_minimum_required(VERSION 3.0)

option(LLVM_ROOT "Source directory of llvm")
option(CLANG_ROOT "Source directory of clang")
option(TAPI_ROOT "Source directory of tapi")
option(LD64_ROOT "Source directory of ld64")

if(NOT LLVM_ROOT)
    set(LLVM_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../llvm")
endif()
if(NOT CLANG_ROOT)
    set(CLANG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../clang")
endif()
if(NOT TAPI_ROOT)
    set(TAPI_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../tapi")
endif()
if(NOT LD64_ROOT)
    set(LD64_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../ld64")
endif()

set(LLVM_ENABLE_EH ON CACHE BOOL "" FORCE)
set(LLVM_ENABLE_RTTI ON CACHE BOOL "" FORCE)

# Skip unnecessary components
set(LLVM_INCLUDE_BENCHMARKS OFF CACHE BOOL "")
set(LLVM_INCLUDE_DOCS OFF CACHE BOOL "")
set(LLVM_INCLUDE_RUNTIMES OFF CACHE BOOL "")
set(LLVM_INCLUDE_TESTS OFF CACHE BOOL "")
set(LLVM_INCLUDE_UTILS OFF CACHE BOOL "")

# Skip unnecessary builds
set(LLVM_BUILD_EXAMPLES OFF CACHE BOOL "")
set(LLVM_BUILD_TOOLS OFF CACHE BOOL "")

# Disable bindings
set(LLVM_ENABLE_BINDINGS OFF CACHE BOOL "")

# Disable unnecessary targets
set(LLVM_TARGETS_TO_BUILD "X86;AArch64;ARM" CACHE STRING "")

# Disable unnecessary install targets
set(LLVM_INSTALL_TOOLCHAIN_ONLY ON CACHE BOOL "")

# Enable clang
set(LLVM_TOOL_CLANG_BUILD ON CACHE BOOL "")
set(LLVM_EXTERNAL_CLANG_SOURCE_DIR "${CLANG_ROOT}" CACHE STRING "")

# Enable tapi and ld64
set(LLVM_EXTERNAL_PROJECTS "tapi;ld64" CACHE STRING "" FORCE)
set(LLVM_EXTERNAL_TAPI_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tapi" CACHE STRING "")
set(LLVM_EXTERNAL_LD64_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ld64" CACHE STRING "" FORCE)

# Skip unnecessary components
set(CLANG_INCLUDE_TESTS OFF CACHE BOOL "")
set(CLANG_INCLUDE_DOCS OFF CACHE BOOL "")

# Disable libxml2 in LLVM
set(LLVM_ENABLE_LIBXML2 OFF CACHE BOOL "")

# Skip unnecessary builds
set(CLANG_BUILD_TOOLS OFF CACHE BOOL "")
set(CLANG_BUILD_EXAMPLES OFF CACHE BOOL "")

add_subdirectory(${LLVM_ROOT} llvm)
