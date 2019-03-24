cmake_minimum_required(VERSION 3.0)

function(cc_check_compile_flag _flag)
    include(CheckCCompilerFlag)
    string(TOUPPER ${_flag} name)
    string(REGEX REPLACE [^A-Z|0-9] _ name ${name})
    set(variable HAVE${name})
    set(flag ${_flag} -Wno-error=unknown-warning)
    check_c_compiler_flag(${_flag} ${variable})
    if(ARGV1)
        set(${ARGV1} ${${variable}} PARENT_SCOPE)
    else()
        set(${variable} ${${variable}} PARENT_SCOPE)
        if(${variable})
            add_compile_options(${_flag})
        endif()
    endif()
endfunction(cc_check_compile_flag)

function(cc_check_headers)
    include(CheckIncludeFile)
    foreach(header ${ARGV})
        string(TOUPPER ${header} name)
        string(REGEX REPLACE [^A-Z|a-z|0-9] _ name ${name})
        set(variable "HAVE_${name}")
        check_include_file(${header} ${variable})
        if(${variable})
            set(${variable} ${${variable}} PARENT_SCOPE)
            add_definitions(-D${variable})
        endif()
    endforeach()
endfunction(cc_check_headers)
