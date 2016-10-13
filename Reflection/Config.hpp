#ifndef CONFIG_HH
#define CONFIG_HH

#include <string>

// A simple config struct
struct Config {
  size_t count;
  std::string strategy;
  const int& hidden;
};


#endif // CONFIG_HH

