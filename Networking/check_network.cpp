#include "check_network.hpp"

namespace snt {
bool isNetworkConnected() {
  return false;
}

bool canConnectToURL(const char* url) {
  if(!isNetworkConnected()) {
    return false;
  }
}

} // namespace snt
