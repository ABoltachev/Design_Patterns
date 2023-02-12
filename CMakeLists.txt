cmake_minimum_required(VERSION 3.16)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 17)

set(sources main.cpp)

add_executable(main ${sources})

add_subdirectory(generative_patterns)

target_link_libraries(main generative_patterns)

target_include_directories(main PRIVATE $<TARGET_PROPERTY:generative_patterns,INTERFACE_INCLUDE_DIRECTORIES>)
