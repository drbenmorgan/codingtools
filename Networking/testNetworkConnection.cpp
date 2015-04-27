#include "check_network.hpp"

int main(int argc, const char *argv[])
{
  return snt::canConnectToURL("http://www.google.com") ? 0 : 1;
}
