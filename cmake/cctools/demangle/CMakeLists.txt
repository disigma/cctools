cmake_minimum_required(VERSION 3.0)

project(demangle)

include_directories(.)
add_definitions(-DIN_GCC -Dxmalloc=malloc -Dxrealloc=realloc)

# http://opensource.apple.com/source/cc/cc-798/cc/demangle.h
# https://opensource.apple.com/source/cc/cc-798/cc/cplus-dem.c
add_library(demangle demangle.c cplus-dem.c)
