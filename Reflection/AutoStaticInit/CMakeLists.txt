# The oddity of Bayeux using boost::serialization's singleton. Appears to be used to
# guarantee calling of ponder registration code, so is that born out?
# - Create a library
add_library(Hidden SHARED Hidden.hpp Hidden.cpp)
add_library(Plugin SHARED Plugin.cpp)
add_executable(HiddenUser HiddenUser.cpp)
target_link_libraries(HiddenUser Hidden)
