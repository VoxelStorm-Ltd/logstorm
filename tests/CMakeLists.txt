include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)

option(LOGSTORM_ENABLE_COVERAGE "Enable code coverage instrumentation" OFF)
if(LOGSTORM_ENABLE_COVERAGE)
  target_compile_options(logstorm PUBLIC --coverage -O0 -g)
  target_link_options(logstorm PUBLIC --coverage)
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

add_executable(logstorm_tests ${TEST_SOURCES})
target_link_libraries(logstorm_tests PRIVATE logstorm Catch2::Catch2WithMain)

if(LOGSTORM_ENABLE_COVERAGE)
  target_compile_options(logstorm_tests PRIVATE --coverage -O0 -g)
  target_link_options(logstorm_tests PRIVATE --coverage)
endif()

include(Catch)
catch_discover_tests(logstorm_tests)
