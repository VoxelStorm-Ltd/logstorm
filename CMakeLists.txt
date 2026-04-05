cmake_minimum_required(VERSION 3.15)
project(logstorm CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost QUIET)

set(LOGSTORM_SOURCES
  logstorm/log_line_helper.cpp
  logstorm/manager.cpp
  logstorm/timestamp.cpp
  logstorm/sink/base.cpp
  logstorm/sink/console.cpp
  logstorm/sink/console_err.cpp
  logstorm/sink/dummy.cpp
  logstorm/sink/file.cpp
  logstorm/sink/fstream.cpp
  logstorm/sink/stream.cpp
)

if(Boost_FOUND)
  list(APPEND LOGSTORM_SOURCES logstorm/sink/circular_buffer.cpp)
endif()

add_library(logstorm STATIC ${LOGSTORM_SOURCES})
target_include_directories(logstorm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(Boost_FOUND)
  target_include_directories(logstorm PUBLIC ${Boost_INCLUDE_DIRS})
  target_compile_definitions(logstorm PUBLIC LOGSTORM_HAS_BOOST)
else()
  message(STATUS "Boost not found - circular_buffer sink will not be built")
endif()

option(LOGSTORM_BUILD_TESTS "Build the logstorm test suite" OFF)
if(LOGSTORM_BUILD_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()
