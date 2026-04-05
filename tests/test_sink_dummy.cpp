#include <catch2/catch_test_macros.hpp>
#include "logstorm/sink/dummy.h"

using logstorm::sink::dummy;
using logstorm::timestamp;

TEST_CASE("dummy sink: can be default-constructed", "[sink][dummy]") {
  CHECK_NOTHROW(dummy{});
}

TEST_CASE("dummy sink: log() does not throw", "[sink][dummy]") {
  dummy d;
  CHECK_NOTHROW(d.log("anything"));
}

TEST_CASE("dummy sink: log() with empty string does not throw", "[sink][dummy]") {
  dummy d;
  CHECK_NOTHROW(d.log(""));
}

TEST_CASE("dummy sink: log_fragment() does not throw", "[sink][dummy]") {
  dummy d;
  CHECK_NOTHROW(d.log_fragment("fragment"));
}

TEST_CASE("dummy sink: repeated log() calls do not throw", "[sink][dummy]") {
  dummy d;
  for(int i = 0; i < 100; ++i) {
    CHECK_NOTHROW(d.log("message " + std::to_string(i)));
  }
}

TEST_CASE("dummy sink: constructed with timestamp type does not throw", "[sink][dummy]") {
  CHECK_NOTHROW(dummy{timestamp::types::DATE_TIME});
}
