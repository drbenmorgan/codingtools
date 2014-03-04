template<typename T=int>
T foo(T arg) {
  return arg;
}

int main()
{
  int intRes = foo(42);
  char charRes = foo<char>('a');

  return ((intRes == 42) && (charRes == 'a')) ? 0 : 1;
}
