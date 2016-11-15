#include "stream.h"

namespace logstorm {
namespace sink {

stream::stream(std::ostream &target_ostream, timestamp::types timestamp_type)
  : base(timestamp_type),
    ostream(target_ostream) {
  /// Default constructor
}

stream::~stream() {
  /// Default destructor
}

void stream::log(std::string const &log_entry) {
  /// Log this line
  #ifndef LOGSTORM_SINGLE_THREADED
    std::lock_guard<std::mutex> lock(output_mutex);
  #endif // LOGSTORM_SINGLE_THREADED
  ostream << time() << log_entry << std::endl;
}
void stream::log_fragment(std::string const &log_entry) {
  /// Log this fragment without ending the line
  #ifndef LOGSTORM_SINGLE_THREADED
    std::lock_guard<std::mutex> lock(output_mutex);
  #endif // LOGSTORM_SINGLE_THREADED
  ostream << log_entry;
}

}
}
