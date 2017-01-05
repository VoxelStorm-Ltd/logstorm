#include "fstream.h"

namespace logstorm {
namespace sink {

fstream::fstream(std::ofstream &target_stream, timestamp::types timestamp_type)
  : base(timestamp_type),
    stream(target_stream) {
  /// Default constructor
}

fstream::~fstream() {
  /// Default destructor
}

void fstream::log(std::string const &log_entry) {
  /// Log this line
  if(stream.good()) {
    #ifndef LOGSTORM_SINGLE_THREADED
      std::lock_guard<std::mutex> lock(output_mutex);
    #endif // LOGSTORM_SINGLE_THREADED
    stream << time() << log_entry << std::endl;
  }
}
void fstream::log_fragment(std::string const &log_entry) {
  /// Log this fragment without ending the line
  if(stream.good()) {
    #ifndef LOGSTORM_SINGLE_THREADED
      std::lock_guard<std::mutex> lock(output_mutex);
    #endif // LOGSTORM_SINGLE_THREADED
    stream << log_entry;
  }
}

}
}
