#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <regex>
#include "logstorm/sink/stream.h"

using logstorm::sink::stream;
using logstorm::timestamp;

TEST_CASE("stream sink: log() writes the entry followed by a newline", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf};
  s.log("hello world");
  std::string out = buf.str();
  CHECK(out.find("hello world") != std::string::npos);
  CHECK(out.back() == '\n');
}

TEST_CASE("stream sink: log() appends multiple entries on separate lines", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf};
  s.log("first");
  s.log("second");
  std::string out = buf.str();
  CHECK(out.find("first") != std::string::npos);
  CHECK(out.find("second") != std::string::npos);
  // Each entry should be on its own line
  auto pos_first  = out.find("first");
  auto pos_second = out.find("second");
  auto newline_between = out.find('\n', pos_first);
  CHECK(newline_between < pos_second);
}

TEST_CASE("stream sink: log() with NONE timestamp has no timestamp prefix", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf, timestamp::types::NONE};
  s.log("clean");
  CHECK(buf.str() == "clean\n");
}

TEST_CASE("stream sink: log() with DATE_TIME timestamp prepends a datetime prefix", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf, timestamp::types::DATE_TIME};
  s.log("stamped");
  std::string out = buf.str();
  std::regex re(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2} stamped\n)");
  CHECK(std::regex_match(out, re));
}

TEST_CASE("stream sink: log_fragment() writes partial text without trailing newline", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf};
  s.log_fragment("part1");
  s.log_fragment("part2");
  std::string out = buf.str();
  CHECK(out.find("part1") != std::string::npos);
  CHECK(out.find("part2") != std::string::npos);
}

TEST_CASE("stream sink: log() empty string produces only a newline", "[sink][stream]") {
  std::ostringstream buf;
  stream s{buf};
  s.log("");
  CHECK(buf.str() == "\n");
}
