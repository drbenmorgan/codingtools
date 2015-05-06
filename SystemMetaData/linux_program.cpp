#include <iostream>
#include <link.h>


int myCallback(struct dl_phdr_info *info, size_t size, void *data) {
  std::cout << info->dlpi_addr << ", " << info->dlpi_name << std::endl;
  return 0;
}


int main(int argc, const char *argv[])
{
  dl_iterate_phdr(myCallback,NULL);

  return 0;
}
