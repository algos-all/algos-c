cmake_minimum_required(VERSION 3.8)
project(algos_c C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17 -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c11 -g")

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
