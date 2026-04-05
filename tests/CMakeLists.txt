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

add_executable(logstorm_tests ${TEST_SOURCES} ${LOGSTORM_SOURCES})
target_include_directories(logstorm_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(logstorm_tests PRIVATE Catch2::Catch2WithMain)

if(Boost_FOUND)
  target_include_directories(logstorm_tests PRIVATE ${Boost_INCLUDE_DIRS})
  target_compile_definitions(logstorm_tests PRIVATE LOGSTORM_HAS_BOOST)
else()
  message(STATUS "Boost not found - circular_buffer sink will not be built")
endif()

option(LOGSTORM_ENABLE_COVERAGE "Enable code coverage instrumentation" OFF)
if(LOGSTORM_ENABLE_COVERAGE)
  target_compile_options(logstorm_tests PRIVATE --coverage -O0 -g)
  target_link_options(logstorm_tests PRIVATE --coverage)
endif()

include(Catch)
catch_discover_tests(logstorm_tests)
