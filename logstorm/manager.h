#ifndef LOGSTORM_MANAGER_H_INCLUDED
#define LOGSTORM_MANAGER_H_INCLUDED

#include <vector>
#include <string>

#include "log_line_helper.h"

namespace logstorm {

namespace sink {
class base;
}

class manager {
  /// Universal logger providing timestamping and simultaneous output to
  /// multiple independent sinks in either line-by-line or stream format.
  ///
  /// Usage:
  ///   logstorm::manager logger;
  ///   logger.add_sink(new logstorm::sink::console);
  ///   logger.add_sink(new logstorm::sink::file("myfile.log", logstorm::timestamp::types::SINCE_START)));
  ///   // different ways to log:
  ///   logger.log("hello world");
  ///   logger("hello world");
  ///   logger("hello ", "world ", 1234);
  ///   logger() << "Hello world! " << 1234;   // note: newline is added automagically
private:
  std::vector<sink::base*> sinks;                                               // the output sinks we're logging to

public:
  manager();
  ~manager();

  void add_sink(sink::base *newsink);
  void log(std::string const &log_entry);

  log_line_helper operator()() {
    /// Generate log line helper as a temporary recipient to stream to
    return log_line_helper(sinks);
  }
  template <typename T> void operator()(T entry) {
    /// Convenience function to log a single entry
    log_line_helper helper(sinks);
    helper << entry;
  }
  template <typename... Args> void operator()(Args&&... entries) {
    /// Convenience function to log any number of arguments
    log_line_helper helper(sinks);
    // now this is a hack... this is the hack of hacks.
    using unpack = int[];
    unpack{0, (helper << entries, 0)...};
  }

  template<typename T> manager &operator<<(T const &rhs) {
    /// Convenience function just to generate a nice error if the << operator is called without () by mistake
    // dirty hack: artificial static assert test that always fails but depends on instantiation (see http://stackoverflow.com/a/16101862/1678468)
    static_assert(sizeof(T) != sizeof(T), "Use operator(), i.e. mylog() << \"my message\";");
    return *this;
  }
};

}

#endif // LOGSTORM_MANAGER_H_INCLUDED
