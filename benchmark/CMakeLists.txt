cmake_minimum_required(VERSION 3.25)
project(freq_Benchmark)
find_package(benchmark REQUIRED)

if(NOT TARGET freq::Lib)
  find_package(freq::Lib CONFIG REQUIRED)
endif()


add_executable(${PROJECT_NAME}
  bmain.cpp
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  benchmark::benchmark
  freq::Lib)
