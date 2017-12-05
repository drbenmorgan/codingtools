#ifndef cetlib_demangle_h
#define cetlib_demangle_h

// ======================================================================
//
// demangle: Call the cross-vendor API to demangle symbols
//           (eg for ROOT dictionary errors).
//
// ======================================================================

#include <string>

#define DEMANGLE_MSG                                                    \
  "\n\n"                                                                \
  "cetlib warning: The 'cet::demangle(std::string const&)' function is deprecated.\n" \
  "                Please use 'cet::demangle_symbol(std::string const&)'.\n\n"

namespace cet {
  std::string demangle_symbol(std::string const & symbol);
  std::string demangle_symbol(char const * symbol);

  std::string demangle_message(std::string mangled);

  [[deprecated(DEMANGLE_MSG)]] std::string demangle(std::string const &mangled);
}

inline
std::string
cet::demangle_symbol(std::string const & symbol)
{
  return demangle_symbol(symbol.c_str());
}

inline
std::string
cet::demangle(std::string const &mangled) {
  return demangle_symbol(mangled);
}

#undef DEMANGLE_MSG
#endif /* cetlib_demangle_h */

// Local Variables:
// mode: c++
// End:
