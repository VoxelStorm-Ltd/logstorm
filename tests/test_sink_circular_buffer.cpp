#include <catch2/catch_test_macros.hpp>
#include "logstorm/sink/circular_buffer.h"

using logstorm::sink::circular_buffer;
using logstorm::timestamp;

TEST_CASE("circular_buffer sink: can be constructed with a given size", "[sink][circular_buffer]") {
  CHECK_NOTHROW(circular_buffer{16});
}

TEST_CASE("circular_buffer sink: initial data is empty", "[sink][circular_buffer]") {
  circular_buffer cb{16};
  CHECK(cb.data.empty());
}

TEST_CASE("circular_buffer sink: log() appends entries", "[sink][circular_buffer]") {
  circular_buffer cb{16};
  cb.log("entry one");
  cb.log("entry two");
  REQUIRE(cb.data.size() == 2);
  CHECK(cb.data[0] == "entry one");
  CHECK(cb.data[1] == "entry two");
}

TEST_CASE("circular_buffer sink: size field matches constructor argument", "[sink][circular_buffer]") {
  circular_buffer cb{32};
  CHECK(cb.size == 32);
}

TEST_CASE("circular_buffer sink: wraps around when full (circular behaviour)", "[sink][circular_buffer]") {
  unsigned int constexpr max{4};
  circular_buffer cb{max};
  for(unsigned int i = 0; i < max + 2; ++i) {
    cb.log("msg" + std::to_string(i));
  }
  // Buffer should still hold exactly max entries
  REQUIRE(cb.data.size() == max);
  // The oldest entries should have been dropped; last entry is the most recent
  CHECK(cb.data.back() == "msg" + std::to_string(max + 1));
  // The front should be the (max+2-max)th = 2nd entry that was pushed
  CHECK(cb.data.front() == "msg2");
}

#ifndef LOGSTORM_COMPOSE_FRAGMENTS_SEPARATELY
TEST_CASE("circular_buffer sink: log_fragment() appends to back entry", "[sink][circular_buffer]") {
  circular_buffer cb{8};
  cb.log("base");
  cb.log_fragment("frag");
  REQUIRE(cb.data.size() == 1);
  CHECK(cb.data[0].find("base") != std::string::npos);
  CHECK(cb.data[0].find("frag") != std::string::npos);
}
#else
TEST_CASE("circular_buffer sink: log_fragment() buffers fragments until newline", "[sink][circular_buffer]") {
  circular_buffer cb{8};
  cb.log("base");
  cb.log_fragment("frag");
  // Fragments without a trailing newline are held in line_in_progress and not yet pushed to the buffer
  REQUIRE(cb.data.size() == 1);
  CHECK(cb.data[0] == "base");

  cb.log_fragment("\n");
  // Once a newline fragment is received, the accumulated line is pushed to the buffer
  REQUIRE(cb.data.size() == 2);
  CHECK(cb.data[0] == "base");
  CHECK(cb.data[1].find("frag") != std::string::npos);
  CHECK(cb.data[1].find('\n') != std::string::npos);
}
#endif

TEST_CASE("circular_buffer sink: log() with timestamp prepends prefix", "[sink][circular_buffer]") {
  circular_buffer cb{8, timestamp::types::SINCE_START};
  cb.log("timed");
  REQUIRE(cb.data.size() == 1);
  // Entry should contain the message text, possibly preceded by a timestamp
  CHECK(cb.data[0].find("timed") != std::string::npos);
}

TEST_CASE("circular_buffer sink: log() with empty string is stored", "[sink][circular_buffer]") {
  circular_buffer cb{8};
  cb.log("");
  REQUIRE(cb.data.size() == 1);
  CHECK(cb.data[0] == "");
}
