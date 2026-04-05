#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <regex>
#include <thread>
#include <chrono>
#include "logstorm/timestamp.h"

using logstorm::timestamp;

TEST_CASE("timestamp: NONE returns empty string", "[timestamp]") {
  timestamp ts{timestamp::types::NONE};
  CHECK(ts() == "");
}

TEST_CASE("timestamp: TIME type returns date format string", "[timestamp]") {
  // The TIME type is mapped to the date format ("%Y-%m-%d ") in the implementation
  timestamp ts{timestamp::types::TIME};
  std::string result = ts();
  CHECK_FALSE(result.empty());
  // Should match YYYY-MM-DD followed by a space
  std::regex re(R"(\d{4}-\d{2}-\d{2} )");
  CHECK(std::regex_match(result, re));
}

TEST_CASE("timestamp: DATE type returns time-of-day format string", "[timestamp]") {
  // The DATE type is mapped to the time format ("%H:%M:%S ") in the implementation
  timestamp ts{timestamp::types::DATE};
  std::string result = ts();
  CHECK_FALSE(result.empty());
  std::regex re(R"(\d{2}:\d{2}:\d{2} )");
  CHECK(std::regex_match(result, re));
}

TEST_CASE("timestamp: DATE_TIME returns a full datetime string", "[timestamp]") {
  timestamp ts{timestamp::types::DATE_TIME};
  std::string result = ts();
  CHECK_FALSE(result.empty());
  std::regex re(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2} )");
  CHECK(std::regex_match(result, re));
}

TEST_CASE("timestamp: UNIX returns a positive integer string", "[timestamp]") {
  timestamp ts{timestamp::types::UNIX};
  std::string result = ts();
  CHECK_FALSE(result.empty());
  // Should be a positive integer followed by a space
  std::regex re(R"(\d+ )");
  CHECK(std::regex_match(result, re));
  long long val = std::stoll(result);
  CHECK(val > 0);
}

TEST_CASE("timestamp: SINCE_START returns a small non-negative float string", "[timestamp]") {
  timestamp ts{timestamp::types::SINCE_START};
  std::string result = ts();
  CHECK_FALSE(result.empty());
  float val = std::stof(result);
  // Should be very small (well under 60 seconds for a unit test run)
  CHECK(val >= 0.0f);
  CHECK(val < 60.0f);
}

TEST_CASE("timestamp: DEFAULT type is NONE", "[timestamp]") {
  timestamp ts;  // default constructor
  CHECK(ts() == "");
}

TEST_CASE("timestamp: SINCE_START advances over time", "[timestamp]") {
  timestamp ts{timestamp::types::SINCE_START};
  float t1 = std::stof(ts());
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  float t2 = std::stof(ts());
  CHECK(t2 >= t1);
}
