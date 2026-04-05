cmake_minimum_required(VERSION 3.15)
project(logstorm_tests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

include(CTest)
enable_testing()
add_subdirectory(tests)
