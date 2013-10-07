// Standard Library
#include <iostream>

// Third Party
// - magic
#include <magic.h>

// This Project

int main(int argc, const char *argv[]) {
  std::string actualFile(argv[1]);
 
  magic_t magicCookie(magic_open(MAGIC_NONE));
  if(!magicCookie) {
    std::cerr << "Failed to initialize libmagic" << std::endl;
    magic_close(magicCookie);
    return 1;
  }

  std::cout << "Loading libmagic database" << std::endl;

  if(magic_load(magicCookie, NULL)) {
    std::cerr << "Failed to load magic database" << std::endl;
    magic_close(magicCookie);
    return 1;
  }

  std::string magicFull(magic_file(magicCookie, actualFile.c_str()));
  std::cout << actualFile << " : " << magicFull << std::endl;

  magic_close(magicCookie);

  return 0;
}

