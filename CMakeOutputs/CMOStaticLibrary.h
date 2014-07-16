// - CMOStaticLibrary : dumb shared lib
#ifndef CMOSTATICLIBRARY_HH
#define CMOSTATICLIBRARY_HH

#include <string>

namespace CMOStaticLibrary {
//! Return name of build mode used to compile the library
std::string getBuildMode();
} // namespace CMOStaticLibrary

#endif // CMOSTATICLIBRARY_HH

