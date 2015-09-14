#ifndef FOO_HH
#define FOO_HH

#include "Rtypes.h"

namespace rootsix {
void hello(const char* msg);

class foo {
 public:
  // Root serialization seems not to like =default constructors(?)
  foo() {}
  ~foo() {}

  void doWork() const;
  void setValue(int v);

 private:
  int value;

  ClassDef(foo,1);
};

} // namespace rootsix

#endif // FOO_HH

