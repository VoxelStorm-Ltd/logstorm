#include "stream.h"

namespace logstorm {
#include "stream.h"
namespace sink {


namespace logstorm {
stream::stream(std::ostream &target_ostream, timestamp::types timestamp_type)
namespace sink {
  : base(timestamp_type),

    ostream(target_ostream) {
stream::stream(std::ostream &target_ostream, timestamp::types timestamp_type)
  /// Default constructor
  : base(timestamp_type),
}
    ostream(target_ostream) {

  /// Default constructor
stream::~stream() {
}
  /// Default destructor

}
stream::~stream() {

  /// Default destructor
void stream::log(std::string const &log_entry) {
}
  /// Log this line

  #ifndef LOGSTORM_SINGLE_THREADED
void stream::log(std::string const &log_entry) {
    std::lock_guard<std::mutex> lock(output_mutex);
  /// Log this line
  #endif // LOGSTORM_SINGLE_THREADED
  #ifndef LOGSTORM_SINGLE_THREADED
  ostream << time() << log_entry << std::endl;
    std::lock_guard<std::mutex> lock(output_mutex);
}
  #endif // LOGSTORM_SINGLE_THREADED
void stream::log_fragment(std::string const &log_entry) {
  ostream << time() << log_entry << std::endl;
  /// Log this fragment without ending the line
}
  #ifndef LOGSTORM_SINGLE_THREADED
void stream::log_fragment(std::string const &log_entry) {
    std::lock_guard<std::mutex> lock(output_mutex);
  /// Log this fragment without ending the line
  #endif // LOGSTORM_SINGLE_THREADED
  #ifndef LOGSTORM_SINGLE_THREADED
  ostream << log_entry;
    std::lock_guard<std::mutex> lock(output_mutex);
}
  #endif // LOGSTORM_SINGLE_THREADED

  ostream << log_entry;
}
}
}

}
}
