struct Foo {
  explicit Foo(int) {}
  explicit operator int() const {return 42;}
};

int main()
{
  Foo a(2);
  Foo b {3};
  int res = static_cast<int>(a);
  
  return (res == 42) ? 0 : 1;
}
