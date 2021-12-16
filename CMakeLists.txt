cmake_minimum_required(VERSION 3.16)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

set(sources main.cpp)

add_executable(main ${sources})

add_subdirectory(generative_patterns)

target_link_libraries(main Generative_patterns_lib)

# target_include_directories(main PRIVATE generative_patterns/include)
