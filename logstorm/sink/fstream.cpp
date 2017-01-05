}

fstream::~fstream() {
  /// Default destructor
#include "fstream.h"
}


namespace logstorm {
void fstream::log(std::string const &log_entry) {
namespace sink {
  /// Log this line

  if(stream.good()) {
fstream::fstream(std::ofstream &target_stream, timestamp::types timestamp_type)
    #ifndef LOGSTORM_SINGLE_THREADED
  : base(timestamp_type),
      std::lock_guard<std::mutex> lock(output_mutex);
    stream(target_stream) {
    #endif // LOGSTORM_SINGLE_THREADED
  /// Default constructor
    stream << time() << log_entry << std::endl;
}
  }

}
fstream::~fstream() {
void fstream::log_fragment(std::string const &log_entry) {
  /// Default destructor
  /// Log this fragment without ending the line
}
  if(stream.good()) {

    #ifndef LOGSTORM_SINGLE_THREADED
void fstream::log(std::string const &log_entry) {
      std::lock_guard<std::mutex> lock(output_mutex);
  /// Log this line
    #endif // LOGSTORM_SINGLE_THREADED
  if(stream.good()) {
    stream << log_entry;
    #ifndef LOGSTORM_SINGLE_THREADED
  }
      std::lock_guard<std::mutex> lock(output_mutex);
}
    #endif // LOGSTORM_SINGLE_THREADED

    stream << time() << log_entry << std::endl;
}
  }
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
