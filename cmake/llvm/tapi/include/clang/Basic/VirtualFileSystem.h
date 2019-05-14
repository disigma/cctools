#ifndef TAPI_CLANG_BASIC_VIRTUALFILESYSTEM_H_
#define TAPI_CLANG_BASIC_VIRTUALFILESYSTEM_H_

#include "llvm/Support/VirtualFileSystem.h"

namespace clang {

namespace vfs {

using namespace llvm::vfs;

}

}

#define clearStatCaches clearStatCache
#define addStatCache setStatCache

#endif // TAPI_CLANG_BASIC_VIRTUALFILESYSTEM_H_
