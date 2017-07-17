#include "Simple.hpp"
#include "TypeWrapper.h"

#include "TBuffer.h"

#include "boost/mpl/size.hpp"
#include "boost/mpl/at.hpp"
#include "boost/mpl/vector.hpp"
#include "boost/mpl/contains.hpp"

#include <iostream>

// Given a variant (equivalently a typelist), can we generate an enum, i.e.
// if we have variant<int, double, bool>, then can we generate
// enum class Types {
//  Int,
//  Double,
//  Bool
//  };?
//  Since enum parameters are identifiers, not immediately obvious

struct Dynamic {
  typedef boost::mpl::vector<int, double, std::string, bool> types;

  template <typename T>
  constexpr auto indexOf() -> typename std::enable_if<boost::mpl::contains<Dynamic::types,T>::type,size_t>::type {
    typedef typename boost::mpl::find<types,T>::type TypeIter;
    return TypeIter::pos::value;
  }
};

// Vistor for reading/writing?
// Otherwise we need some way to obtain type at runtime index given variant::types
// (presumed to be a typelist)
// Writing is o.k through visitor as operators are passed actual types, so
// buffer should handle writing automatically.
// Reading not so easy as need to take action based on runtime value of
// type index (so do need metaprogramming or similar at this point
// e.g,
//
// if(index = 0) read_int
// elif(index = 1) read_double
// elif(index =2 ) read_string
// ... etc ...
// for limited set of values, can do this by hand.
// Aimed at metadata, so performance less critical.

struct PrintVisitor : public boost::static_visitor<> {
  template <typename T>
  void operator()(const T& v) const {
    std::cout << v;
  }

  void operator()(const std::vector<int>& v) const {
    std::cout << "{";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "}";
  }
};


struct WriteTBufferVisitor : public boost::static_visitor<> {
  explicit WriteTBufferVisitor(TBuffer& buf) : R__b_(buf) {}
  TBuffer& R__b_;

  template<typename T>
  void operator()(const T& v) const {
    TypeWrapper<T> tmp;
    tmp.value = v;
    R__b_.WriteClassBuffer(TypeWrapper<T>::Class(), &tmp);
  }
};

struct ReadTBufferVisitor : public boost::static_visitor<Simple::value_type> {
  explicit ReadTBufferVisitor(TBuffer& buf) : R__b_(buf) {}
  TBuffer& R__b_;

  template <typename T>
  Simple::value_type operator()(const T& v) {
    TypeWrapper<T> tmpI;
    R__b_.ReadClassBuffer(TypeWrapper<T>::Class(), &tmpI);
    return tmpI.value;
  }
};



struct MakeVariant {
  template <typename T>
  Simple::value_type operator()() {
    return T {};
  }
};


// Type switches *cannot* handle fully variant return types, (might be possible
// in C++14 with auto returns, but even then conversions might be invoked.
// Rather, try to return an actual variant initialized with the correct type.
template <typename TypeList, unsigned int Index = 0, bool Stop = ( Index == boost::mpl::size<TypeList>::type::value )>
struct TypeSwitch {
  template <class Functor>
  auto operator()( unsigned int i, Functor f )
  -> decltype( f.template operator()<typename boost::mpl::at_c<TypeList, Index>::type>() )
  {
    if( i == Index )
      return f.template operator()<typename boost::mpl::at_c<TypeList, Index>::type>();
    else
    {
      TypeSwitch<TypeList, Index + 1> next;
      return next.operator()( i, f );
    }
  }
};

/**
  Handles the base case when the type cannot be found. This works because we
  specialize over the value of the "Stop" variable.
*/
struct EmptyType {};
template <typename TypeList, unsigned int Index>
struct TypeSwitch<TypeList, Index, true> {
  template <class Functor>
  auto operator()( unsigned int /* i */, Functor /* f */ )
  -> decltype( Functor().template operator()<EmptyType>() )
  {
    throw std::runtime_error( "Index is out of range" );
  }
};


// This should be identical to generated streamer...
void Simple::Streamer(TBuffer &R__b) {
  // Stream an object of class Simple.
  if (R__b.IsReading()) {
    // Now read the type index
    int index {0};
    R__b >> index;
    // Process is - initialize variant to hold appropriate type
    //              Use self-visitation to assign correct value
    value_ = TypeSwitch<DynamicType::types>()(index, MakeVariant());
    ReadTBufferVisitor bufferVisitor(R__b);
    value_ = boost::apply_visitor(bufferVisitor, value_);

    std::cout << "read : ";
  } else {
    // Now, we should write the index of the type. This is an int
    R__b << value_.which();
    // ? Now write the remainder of the buffer as determined by the type index
    WriteTBufferVisitor bufferVisitor(R__b);
    boost::apply_visitor(bufferVisitor, value_);

    std::cout << "written : ";
  }

  std::cout << this << ", " << value_.which() << ", ";
  boost::apply_visitor(PrintVisitor(), value_);
  std::cout << std::endl;
}

