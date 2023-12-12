cmake_minimum_required(VERSION 3.25)
project(freq LANGUAGES CXX)
find_package(GTest)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(src)

enable_testing()
add_subdirectory(test)
add_subdirectory(benchmark)
