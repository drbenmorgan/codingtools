// - CMOSharedLibrary : implementation

#include "CMOSharedLibrary.h"

//! Stringify supplied argument
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

namespace CMOSharedLibrary {
std::string getBuildMode() {
#if defined(CMO_BUILD_TYPE)
  return TOSTRING(CMO_BUILD_TYPE);
#else
  return "UNDEFINED";
#endif
}
} // namespace CMOSha
