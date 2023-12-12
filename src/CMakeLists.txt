cmake_minimum_required(VERSION 3.25)
project(freq_bin)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(lib)
include(GNUInstallDirs)

add_executable(freq main.cpp)
target_link_libraries(freq PRIVATE freq-Lib)
target_compile_features(freq INTERFACE cxx_std_20)
target_compile_options(freq PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(freq PRIVATE "$<$<CONFIG:Debug>:-O0>")
install(TARGETS freq EXPORT freq-targets)
