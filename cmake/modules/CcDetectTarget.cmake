cmake_minimum_required(VERSION 3.0)

function(cc_detect_target PREFIX)
    # https://sourceforge.net/p/predef/wiki/Architectures/
    # https://abseil.io/docs/cpp/platforms/macros
    include(CheckCSourceCompiles)

    unset(ARCH_ARM)
    check_c_source_compiles(
        "
            #if defined(__arm__) || defined(_M_ARM)
            int main() {}
            #endif
        "
        ARCH_ARM
    )

    unset(ARCH_ARM64)
    check_c_source_compiles(
        "
            #if defined(__aarch64__)
            int main() {}
            #endif
        "
        ARCH_ARM64
    )

    unset(ARCH_X86)
    check_c_source_compiles(
        "
            #if defined(__i386__) || defined(_M_IX86)
            int main() {}
            #endif
        "
        ARCH_X86
    )

    unset(ARCH_X86_64)
    check_c_source_compiles(
        "
            #if defined(__x86_64__) || defined(_M_X64)
            int main() {}
            #endif
        "
        ARCH_X86_64
    )

    unset(OS_ANDROID)
    check_c_source_compiles(
        "
            #if defined(__ANDROID__)
            int main() {}
            #endif
        "
        OS_ANDROID
    )

    unset(OS_LINUX)
    check_c_source_compiles(
        "
            #if defined(__linux__)
            int main() {}
            #endif
        "
        OS_LINUX
    )

    unset(OS_UNIX)
    check_c_source_compiles(
        "
            #if defined(__unix__)
            int main() {}
            #endif
        "
        OS_UNIX
    )

    unset(OS_CYGWIN)
    check_c_source_compiles(
        "
            #if defined(__CYGWIN__)
            int main() {}
            #endif
        "
        OS_CYGWIN
    )

    unset(OS_WIN)
    check_c_source_compiles(
        "
            #if defined(_WIN32)
            int main() {}
            #endif
        "
        OS_WIN
    )

    unset(OS_DARWIN)
    check_c_source_compiles(
        "
            #if defined(__APPLE__)
            int main() {}
            #endif
        "
        OS_DARWIN
    )

    unset(OS_IOS)
    check_c_source_compiles(
        "
            #if defined(__APPLE__)
            #include <TargetConditionals.h>
            #if TARGET_OS_IPHONE
            int main() {}
            #endif
            #endif
        "
        OS_IOS
    )

    unset(OS_MAC)
    check_c_source_compiles(
        "
            #if defined(__APPLE__)
            #include <TargetConditionals.h>
            #if TARGET_OS_MAC
            int main() {}
            #endif
            #endif
        "
        OS_MAC
    )

    option(CC_MULTI_ARCH_64BIT "64-bit preferred when multi-arch detected" ON)
    option(CC_MULTI_ARCH_32BIT "32-bit preferred when multi-arch detected" OFF)

    if(CC_MULTI_ARCH_64BIT AND CC_MULTI_ARCH_32BIT)
        message(FATAL_ERROR "Unable to support both 32-bit and 64-bit")
    endif()

    if(ARCH_ARM AND ARCH_ARM64)
        if(CC_MULTI_ARCH_64BIT)
            add_compile_options(-arch arm64)
            set(ARCH_ARM OFF)
        elseif(CC_MULTI_ARCH_32BIT)
            add_compile_options(-arch armv7)
            set(ARCH_ARM64 OFF)
        else()
            message(
                FATAL_ERROR
                "Multi-arch detected, please set CC_MULTI_ARCH_64BIT or "
                "CC_MULTI_ARCH_32BIT to select the target arch"
            )
        endif()
    endif()

    if(ARCH_X86 AND ARCH_X86_64)
        if(CC_MULTI_ARCH_64BIT)
            add_compile_options(-arch x86_64)
            set(ARCH_X86 OFF)
        elseif(CC_MULTI_ARCH_32BIT)
            add_compile_options(-arch i386)
            set(ARCH_X86_64 OFF)
        else()
            message(
                FATAL_ERROR
                "Multi-arch detected, please set CC_MULTI_ARCH_64BIT or "
                "CC_MULTI_ARCH_32BIT to select the target arch"
            )
        endif()
    endif()

    unset(TRIPLE)
    if(ARCH_ARM)
        if(TRIPLE)
            message(FATAL_ERROR "Multi-arch is currently unsupported.")
        elseif(OS_ANDROID)
            set(TRIPLE armv7-linux-androideabi)
        elseif(OS_IOS)
            set(TRIPLE armv7-apple-darwin)
        else()
            message(FATAL_ERROR "Unknown os for arm")
        endif()
    endif()

    if(ARCH_ARM64)
        if(TRIPLE)
            message(FATAL_ERROR "Multi-arch is currently unsupported.")
        elseif(OS_IOS)
            set(TRIPLE aarch64-apple-darwin)
        else()
            message(FATAL_ERROR "Unknown os for arm64")
        endif()
    endif()

    if(ARCH_X86)
        if(TRIPLE)
            message(FATAL_ERROR "Multi-arch is currently unsupported.")
        elseif(OS_ANDROID)
            set(TRIPLE i686-linux-android)
        elseif(OS_DARWIN)
            set(TRIPLE i386-apple-darwin)
        elseif(OS_CYGWIN)
            set(TRIPLE i686-pc-cygwin)
        elseif(OS_LINUX)
            set(TRIPLE i386-linux-gnu)
        else()
            message(FATAL_ERROR "Unknown os for x86")
        endif()
    endif()

    if(ARCH_X86_64)
        if(TRIPLE)
            message(FATAL_ERROR "Multi-arch is currently unsupported.")
        elseif(OS_ANDROID)
            set(TRIPLE x86_64-linux-android)
        elseif(OS_DARWIN)
            set(TRIPLE x86_64-apple-darwin)
        elseif(OS_CYGWIN)
            set(TRIPLE x86_64-pc-cygwin)
        elseif(OS_LINUX)
            set(TRIPLE x86_64-linux-gnu)
        else()
            message(FATAL_ERROR "Unknown os for x86_64")
        endif()
    endif()

    if(NOT TRIPLE)
        message(FATAL_ERROR "Unable to detect the target triple")
    endif()

    set(${PREFIX}_ARCH_ARM ${ARCH_ARM} CACHE BOOL "")
    set(${PREFIX}_ARCH_ARM64 ${ARCH_ARM64} CACHE BOOL "")
    set(${PREFIX}_ARCH_X86 ${ARCH_X86} CACHE BOOL "")
    set(${PREFIX}_ARCH_X86_64 ${ARCH_X86_64} CACHE BOOL "")
    set(${PREFIX}_OS_ANDROID ${OS_ANDROID} CACHE BOOL "")
    set(${PREFIX}_OS_LINUX ${OS_LINUX} CACHE BOOL "")
    set(${PREFIX}_OS_UNIX ${OS_UNIX} CACHE BOOL "")
    set(${PREFIX}_OS_CYGWIN ${OS_CYGWIN} CACHE BOOL "")
    set(${PREFIX}_OS_WIN ${OS_WIN} CACHE BOOL "")
    set(${PREFIX}_OS_DARWIN ${OS_DARWIN} CACHE BOOL "")
    set(${PREFIX}_OS_IOS ${OS_IOS} CACHE BOOL "")
    set(${PREFIX}_OS_MAC ${OS_MAC} CACHE BOOL "")
    set(${PREFIX}_TRIPLE ${TRIPLE} CACHE STRING "")
endfunction(cc_detect_target)
