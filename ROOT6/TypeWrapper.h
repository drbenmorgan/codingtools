#ifndef TYPEWRAPPER_HH
#define TYPEWRAPPER_HH
/// A very dumb value holder
template<typename T>
struct TypeWrapper {
  T value;
  ClassDef(TypeWrapper,1);
};

#endif // TYPEWRAPPER_HH

