cmake_minimum_required(VERSION 3.15)
project(logstorm_tests CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)

find_package(Boost QUIET)

set(LOGSTORM_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/log_line_helper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/manager.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/timestamp.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/base.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/console.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/console_err.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/dummy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/file.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/fstream.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/stream.cpp
)

if(Boost_FOUND)
  list(APPEND LOGSTORM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../logstorm/sink/circular_buffer.cpp)
endif()

set(TEST_SOURCES
  test_manager.cpp
  test_timestamp.cpp
  test_sink_stream.cpp
  test_sink_dummy.cpp
)

if(Boost_FOUND)
  list(APPEND TEST_SOURCES test_sink_circular_buffer.cpp)
endif()

option(LOGSTORM_ENABLE_COVERAGE "Enable code coverage instrumentation" OFF)

include(Catch)

# Helper to create a logstorm test executable with a specific set of compile defines.
# Usage: add_logstorm_test_variant(<target> [DEFINES def1 def2 ...])
function(add_logstorm_test_variant target_name)
  cmake_parse_arguments(ARG "" "" "DEFINES" ${ARGN})
  add_executable(${target_name} ${TEST_SOURCES} ${LOGSTORM_SOURCES})
  target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
  target_link_libraries(${target_name} PRIVATE Catch2::Catch2WithMain)
  set(_defines ${ARG_DEFINES})
  if(Boost_FOUND)
    target_include_directories(${target_name} PRIVATE ${Boost_INCLUDE_DIRS})
    list(APPEND _defines LOGSTORM_HAS_BOOST)
  endif()
  if(_defines)
    target_compile_definitions(${target_name} PRIVATE ${_defines})
  endif()
  if(LOGSTORM_ENABLE_COVERAGE)
    target_compile_options(${target_name} PRIVATE --coverage -O0 -g)
    target_link_options(${target_name} PRIVATE --coverage)
  endif()
  catch_discover_tests(${target_name})
endfunction()

# Default build – no extra defines
add_logstorm_test_variant(logstorm_tests)

# Build with LOGSTORM_COMPOSE_FRAGMENTS_SEPARATELY: fragments are buffered until
# a newline is received before being written to the sink as a complete line.
add_logstorm_test_variant(logstorm_tests_compose_separately
  DEFINES LOGSTORM_COMPOSE_FRAGMENTS_SEPARATELY)

# Build with LOGSTORM_SINGLE_THREADED: mutex synchronisation is omitted.
add_logstorm_test_variant(logstorm_tests_single_threaded
  DEFINES LOGSTORM_SINGLE_THREADED)

if(NOT Boost_FOUND)
  message(STATUS "Boost not found - circular_buffer sink will not be built")
endif()
