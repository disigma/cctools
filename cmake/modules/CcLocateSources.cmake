cmake_minimum_required(VERSION 3.0)

function(cc_locate_sources _sources _prefix)
    set(sources)
    foreach(source ${ARGN})
        list(APPEND sources "${_prefix}/${source}")
    endforeach()
    set(${_sources} ${sources} PARENT_SCOPE)
endfunction(cc_locate_sources)
