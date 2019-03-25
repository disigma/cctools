cmake_minimum_required(VERSION 3.0)

include_directories($<TARGET_PROPERTY:clangBasic,INCLUDE_DIRECTORIES>)

aux_source_directory(tapi TAPI_SOURCES)
llvm_add_library(tapi ${TAPI_SOURCES} DEPENDS clangBasic)
