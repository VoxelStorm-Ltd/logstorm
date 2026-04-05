#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <memory>
#include "logstorm/manager.h"
#include "logstorm/sink/stream.h"
#include "logstorm/sink/dummy.h"

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static std::pair<logstorm::manager, std::shared_ptr<std::ostringstream>>
make_manager_with_stream() {
  auto buf = std::make_shared<std::ostringstream>();
  logstorm::manager mgr;
  mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf));
  return {std::move(mgr), buf};
}

// ---------------------------------------------------------------------------
// add_sink / get_sink
// ---------------------------------------------------------------------------

TEST_CASE("manager: add_sink(shared_ptr) returns sequential ids", "[manager]") {
  logstorm::manager mgr;
  size_t id0 = mgr.add_sink(std::make_shared<logstorm::sink::dummy>());
  size_t id1 = mgr.add_sink(std::make_shared<logstorm::sink::dummy>());
  CHECK(id0 == 0);
  CHECK(id1 == 1);
}

TEST_CASE("manager: add_sink<T>() template overload returns correct id", "[manager]") {
  logstorm::manager mgr;
  size_t id = mgr.add_sink<logstorm::sink::dummy>();
  CHECK(id == 0);
}

TEST_CASE("manager: get_sink returns the sink that was added", "[manager]") {
  logstorm::manager mgr;
  auto sink = std::make_shared<logstorm::sink::dummy>();
  size_t id = mgr.add_sink(sink);
  CHECK(mgr.get_sink(id) == sink);
}

TEST_CASE("manager: get_sink throws for out-of-range id", "[manager]") {
  logstorm::manager mgr;
  CHECK_THROWS_AS(mgr.get_sink(0), std::out_of_range);
}

// ---------------------------------------------------------------------------
// remove_sink
// ---------------------------------------------------------------------------

TEST_CASE("manager: remove_sink removes the correct sink", "[manager]") {
  auto buf0 = std::make_shared<std::ostringstream>();
  auto buf1 = std::make_shared<std::ostringstream>();
  logstorm::manager mgr;
  size_t id0 = mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf0));
  mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf1));
  mgr.remove_sink(id0);
  mgr.log("hello");
  CHECK(buf0->str().empty());
  CHECK(buf1->str().find("hello") != std::string::npos);
}

TEST_CASE("manager: remove_sink with out-of-range id is a no-op", "[manager]") {
  logstorm::manager mgr;
  CHECK_NOTHROW(mgr.remove_sink(99));
}

// ---------------------------------------------------------------------------
// clear_sinks
// ---------------------------------------------------------------------------

TEST_CASE("manager: clear_sinks removes all sinks", "[manager]") {
  auto buf = std::make_shared<std::ostringstream>();
  logstorm::manager mgr;
  mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf));
  mgr.clear_sinks();
  mgr.log("should not appear");
  CHECK(buf->str().empty());
}

// ---------------------------------------------------------------------------
// log()
// ---------------------------------------------------------------------------

TEST_CASE("manager: log() sends text to sink", "[manager]") {
  auto [mgr, buf] = make_manager_with_stream();
  mgr.log("test message");
  CHECK(buf->str().find("test message") != std::string::npos);
}

TEST_CASE("manager: log() sends to multiple sinks", "[manager]") {
  auto buf0 = std::make_shared<std::ostringstream>();
  auto buf1 = std::make_shared<std::ostringstream>();
  logstorm::manager mgr;
  mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf0));
  mgr.add_sink(std::make_shared<logstorm::sink::stream>(*buf1));
  mgr.log("multi-sink");
  CHECK(buf0->str().find("multi-sink") != std::string::npos);
  CHECK(buf1->str().find("multi-sink") != std::string::npos);
}

TEST_CASE("manager: log() with no sinks does not throw", "[manager]") {
  logstorm::manager mgr;
  CHECK_NOTHROW(mgr.log("nothing"));
}

// ---------------------------------------------------------------------------
// operator()
// ---------------------------------------------------------------------------

TEST_CASE("manager: operator() single argument", "[manager]") {
  auto [mgr, buf] = make_manager_with_stream();
  mgr("single arg");
  CHECK(buf->str().find("single arg") != std::string::npos);
}

TEST_CASE("manager: operator() multiple arguments are concatenated", "[manager]") {
  auto [mgr, buf] = make_manager_with_stream();
  mgr("hello ", "world ", 42);
  std::string out = buf->str();
  CHECK(out.find("hello ") != std::string::npos);
  CHECK(out.find("world ") != std::string::npos);
  CHECK(out.find("42") != std::string::npos);
}

// ---------------------------------------------------------------------------
// operator<<
// ---------------------------------------------------------------------------

TEST_CASE("manager: operator<< streams text to sink", "[manager]") {
  auto [mgr, buf] = make_manager_with_stream();
  mgr << "streamed " << 123;
  CHECK(buf->str().find("streamed 123") != std::string::npos);
}

// ---------------------------------------------------------------------------
// build_with_sink static factory
// ---------------------------------------------------------------------------

TEST_CASE("manager: build_with_sink<T> creates a ready-to-use manager", "[manager]") {
  std::ostringstream buf;
  auto mgr = logstorm::manager::build_with_sink<logstorm::sink::stream>(buf);
  mgr.log("factory built");
  CHECK(buf.str().find("factory built") != std::string::npos);
}
