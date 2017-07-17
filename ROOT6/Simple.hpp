#ifndef SIMPLE_HH
#define SIMPLE_HH

// Need TObject/ClassDef to get class Streamer method?
#include "TObject.h"
#include "boost/variant.hpp"
#include <string>

class Simple {
 public:
  typedef boost::variant<int,
                         double,
                         std::string,
                         std::vector<int> > value_type;

 public:
  Simple() = default;
  ~Simple() = default;

  template <typename T>
  void setValue(const T& v) {
    value_ = v;
  }

  // Needed to get Streamer to customize?
  // As streamer requires hand-managing, key schema
  // evolution issue is the list of types in the variant
  // and their order!
  ClassDef(Simple, 1);

 private:
  typedef value_type DynamicType;
  DynamicType value_; //! Transient only, storage handled separately
};

#endif // SIMPLE_HH

