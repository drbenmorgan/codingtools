#ifndef CHECK_NETWORK_HH
#define CHECK_NETWORK_HH

namespace snt {
/// return true if the local host has an active network connection
bool isNetworkConnected();

/// return true if the supplied URL can be reached
bool canConnectToURL(const char* url);
}
#endif // CHECK_NETWORK_HH

