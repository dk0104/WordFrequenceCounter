cmake_minimum_required(VERSION 3.25)
project(freq_Tests CXX)
#find_package(GTest REQUIRED)

if(NOT TARGET freq::Lib)
  find_package(freq::Lib CONFIG REQUIRED)
endif()

add_executable(freq_Tests 
  test_wfc_trie.cpp 
  test_wfc_map.cpp)

target_link_libraries(${PROJECT_NAME}
  PRIVATE 
   GTest::gtest
   GTest::gtest_main
   freq::Lib)

include(GoogleTest)
gtest_discover_tests(freq_Tests)
