#include "Hidden.hpp"

#include <iostream>
#include <dlfcn.h>

void loadPlugin() {
  // Mac specific for now...
  void* handle = dlopen("libPlugin.dylib", RTLD_LAZY);
  std::cout << "got handle ptr " << handle << "\n";
}

int main(int argc, char *argv[])
{
  hidden::hidden();

  loadPlugin();
  return 0;
}
