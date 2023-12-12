cmake_minimum_required(VERSION 3.24)

set(SRC 
  wfc_trie.cpp 
  wfc_map.cpp)
set(HDR 
  include/wfc_trie.h 
  include/wfc_map.h)

add_library(freq-Lib ${SRC} ${HDR})

target_compile_features(freq-Lib PUBLIC cxx_std_20)
target_compile_options(freq-Lib PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(freq-Lib PRIVATE "$<$<CONFIG:Debug>:-O0>")
target_include_directories(freq-Lib PUBLIC include)

add_library(freq::Lib ALIAS freq-Lib)
