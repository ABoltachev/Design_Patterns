cmake_minimum_required(VERSION 3.16)
project(Generative_patterns_lib)

set(CMAKE_CXX_STANDARD 14)

# set(sources src/singleton.cpp
#             src/abstract_factory.cpp)

file(GLOB sources src/*.cpp)

add_library(Generative_patterns_lib SHARED ${sources})

target_include_directories(Generative_patterns_lib PUBLIC include)
