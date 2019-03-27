cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/modules")

add_subdirectory(libobjc2)
add_subdirectory(cctools)
add_subdirectory(llvm)

add_dependencies(cctools tapi)
