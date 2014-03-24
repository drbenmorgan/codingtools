struct Foo {
  explicit Foo(int) {}
  explicit operator int() const {return 42;}
};

int int main(int argc, const char *argv[])
{
  Foo a = 1;
  Foo b(2);
  int baz = b;
  return 1;
}
