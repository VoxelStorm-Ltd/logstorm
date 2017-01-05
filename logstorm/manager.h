  ///   logstorm::manager logger;
  ///   logger.add_sink(new logstorm::sink::console);
  ///   logger.add_sink(new logstorm::sink::file("myfile.log", logstorm::timestamp::types::SINCE_START)));
  ///   // different ways to log:
  ///   logger.log("hello world");
#ifndef LOGSTORM_MANAGER_H_INCLUDED
  ///   logger("hello world");
#define LOGSTORM_MANAGER_H_INCLUDED
  ///   logger("hello ", "world ", 1234);

  ///   logger << "Hello world! " << 1234;   // note: newline is added automagically
#include <vector>
private:
#include <string>

  std::vector<sink::base*> sinks;                                               // the output sinks we're logging to
#include "log_line_helper.h"


public:
namespace logstorm {
  manager();

  ~manager();
namespace sink {

class base;
  void add_sink(sink::base *newsink);
}
  void log(std::string const &log_entry);


class manager {
  log_line_helper operator()() __attribute__((__deprecated__("Using () is not required in combination with the stream operator."))) {
  /// Universal logger providing timestamping and simultaneous output to
    /// Generate log line helper as a temporary recipient to stream to
  /// multiple independent sinks in either line-by-line or stream format.
    return log_line_helper(sinks);
  ///
  }
  /// Usage:
  ///   logstorm::manager logger;
  template <typename T> inline constexpr void operator()(T entry) {
  ///   logger.add_sink(new logstorm::sink::console);
    /// Convenience function to log a single entry
  ///   logger.add_sink(new logstorm::sink::file("myfile.log", logstorm::timestamp::types::SINCE_START)));
    log_line_helper helper(sinks);
  ///   // different ways to log:
    helper << entry;
  ///   logger.log("hello world");
  }
  ///   logger("hello world");
  template <typename... Args> inline constexpr void operator()(Args&&... entries) {
  ///   logger("hello ", "world ", 1234);
    /// Convenience function to log any number of arguments
  ///   logger << "Hello world! " << 1234;   // note: newline is added automagically
    log_line_helper helper(sinks);
private:
    // now this is a hack... this is the hack of hacks.
  std::vector<sink::base*> sinks;                                               // the output sinks we're logging to
    using unpack = int[];

    unpack{0, (helper << entries, 0)...};
public:
  }
  manager();

  ~manager();
  /*

  void add_sink(sink::base *newsink);
  template<typename T> inline constexpr manager &operator<<(T const &rhs) {
  void log(std::string const &log_entry);
    /// Convenience function just to generate a nice error if the << operator is called without () by mistake

    // dirty hack: artificial static assert test that always fails but depends on instantiation (see http://stackoverflow.com/a/16101862/1678468)
  log_line_helper operator()() __attribute__((__deprecated__("Using () is not required in combination with the stream operator."))) {
    static_assert(sizeof(T) != sizeof(T), "Use operator(), i.e. mylog() << \"my message\";");
    /// Generate log line helper as a temporary recipient to stream to
    return *this;
    return log_line_helper(sinks);
  }
  }
  */
  template <typename T> inline constexpr void operator()(T entry) {
  template<typename T> inline constexpr log_line_helper operator<<(T const &rhs) {
    /// Convenience function to log a single entry
    /// Produce a log line helper and return it for further streaming
    log_line_helper helper(sinks);
    log_line_helper helper(sinks);
    helper << entry;
  }
    helper << rhs;
  template <typename... Args> inline constexpr void operator()(Args&&... entries) {
    return helper;
    /// Convenience function to log any number of arguments
  }
    log_line_helper helper(sinks);
};
    // now this is a hack... this is the hack of hacks.

    using unpack = int[];
}
    unpack{0, (helper << entries, 0)...};

  }
#endif // LOGSTORM_MANAGER_H_INCLUDED

  /*
  template<typename T> inline constexpr manager &operator<<(T const &rhs) {
    /// Convenience function just to generate a nice error if the << operator is called without () by mistake
    // dirty hack: artificial static assert test that always fails but depends on instantiation (see http://stackoverflow.com/a/16101862/1678468)
    static_assert(sizeof(T) != sizeof(T), "Use operator(), i.e. mylog() << \"my message\";");
    return *this;
  }
  */
  template<typename T> inline constexpr log_line_helper operator<<(T const &rhs) {
    /// Produce a log line helper and return it for further streaming
    log_line_helper helper(sinks);
    helper << rhs;
    return helper;
  }
};

}

#endif // LOGSTORM_MANAGER_H_INCLUDED
