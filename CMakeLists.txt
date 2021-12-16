cmake_minimum_required(VERSION 3.16)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(Design_Patterns main.cpp src/singleton.cpp src/abstract_factory.cpp)

target_include_directories(Design_Patterns PUBLIC include)
