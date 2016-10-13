cmake_minimum_required(VERSION 3.5)
project(ProtoBuf VERSION 0.1.0)

# - Strict C++11 requirement
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# - Need protobuf
find_package(Protobuf REQUIRED)

# - Try and generate the C++ files
protobuf_generate_cpp(CONFIG_PB_HDRS CONFIG_PB_SRCS config.proto)

# - Build a library from them
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Protobuf_INCLUDE_DIRS})
add_library(config_pb SHARED ${CONFIG_PB_HDRS} ${CONFIG_PB_SRCS})
target_link_libraries(config_pb ${Protobuf_LIBRARIES})
