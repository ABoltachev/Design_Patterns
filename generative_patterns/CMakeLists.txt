cmake_minimum_required(VERSION 3.16)
project(GenerativePatternsLib)

set(CMAKE_CXX_STANDARD 17)

file(GLOB sources src/*.cpp)

add_library(generative_patterns SHARED ${sources})

target_include_directories(generative_patterns PUBLIC include)
