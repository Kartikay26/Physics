cmake_minimum_required(VERSION 3.13)
project(physics)

set(CMAKE_CXX_STANDARD 17)

add_library(physics physics.cpp physics.h main.cpp vec3.cpp vec3.h)
add_executable(main main.cpp)
target_link_libraries(main physics)
