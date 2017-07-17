#ifndef DYNAMIC_HH
#define DYNAMIC_HH

/// A simple dynamic type that can store a fixed ste of types
/// Remember that this is trying to store structures of the
// form
//
// {
//   foo : string = "foo"
//   bar : real = 3.14
//   seq : real = {1.2, 3.4, 5.6}
//   baz : properties {
//     sub : string = "sub"
//   }
// }
//
// Nice, but not critical, to have iteration, e.g.
// Dynamic d = {1,2,3,4}
// for (auto e : d) {
//   doSomething(d)
// }
// Issue is that iterator is typed, but only determined at runtime

// Standard Library
#include <type_traits>
#include <vector>

// Third Party
// - Boost
#include "boost/mpl/vector.hpp"
#include "boost/mpl/contains.hpp"
#include "boost/mpl/transform.hpp"

#include "boost/variant.hpp"

// String interpreted as a filesystem Path
struct Path {
  std::string value;
};

// Number interpreted as a physical quantity
struct Quantity {
  double value;
  std::string unit;
};


class Dynamic {
 public:
  // Could use typedefs to clarify held types
  typedef int Integer;
  typedef double Real;
  typedef std::string String;
  typedef bool Bool;
  typedef std::vector<int> IntegerList;
  typedef std::vector<double> RealList;
  typedef std::vector<bool> BoolList;

  typedef boost::mpl::vector<int,
                             double,
                             std::string,
                             bool,
                             std::vector<int>,
                             std::vector<double>,
                             std::vector<std::string>,
                             std::vector<bool>,
                             Path,
                             Quantity
                             > types;
  typedef boost::make_variant_over<types>::type value_type;


 public:
  Dynamic() = default;
  ~Dynamic() = default;

  size_t type() const {
    return value_.which();
  }

  template <typename T>
  bool holds() const {
    return this->type() == this->indexOf<T>();
  }

  template <typename T>
  auto indexOf() const
  -> typename std::enable_if<boost::mpl::contains<Dynamic::types,T>::type::value,size_t>::type {
    typedef typename boost::mpl::find<types,T>::type TypeIter;
    return TypeIter::pos::value;
  }


  template <typename T>
  auto get()
  -> typename std::enable_if<boost::mpl::contains<Dynamic::types,T>::type::value,T&>::type {
    return boost::get<T>(value_);
  }

  template <typename T>
  auto set(T t)
  -> typename std::enable_if<boost::mpl::contains<Dynamic::types,T>::type::value>::type {
    value_ = t;
  }

 private:
  value_type value_;
};




// Given a struct, want to be able to do
// MyStruct make(pset) {
//   for(member in struct) {
//     struct.member = pset.get<typeof_member>(member)



#endif // DYNAMIC_HH

