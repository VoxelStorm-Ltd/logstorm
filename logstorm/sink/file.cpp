    std::cout << "LogStorm: WARNING: Couldn't open logfile" << target_filename << std::endl;
  }
}

#include "file.h"
#include <iostream>
file::~file() {

  /// Default destructor
namespace logstorm {
  #ifndef LOGSTORM_SINGLE_THREADED
namespace sink {
    std::lock_guard<std::mutex> lock(output_mutex);

  #endif // LOGSTORM_SINGLE_THREADED
file::file(std::string const &target_filename, timestamp::types timestamp_type)
  stream.close();
  : base(timestamp_type),
}
    stream(target_filename, std::ios_base::app) {

  /// Default constructor
void file::log(std::string const &log_entry) {
  if(!stream.good()) {
  /// Log this line
    std::cout << "LogStorm: WARNING: Couldn't open logfile" << target_filename << std::endl;
  if(stream.good()) {
  }
    #ifndef LOGSTORM_SINGLE_THREADED
}
      std::lock_guard<std::mutex> lock(output_mutex);

    #endif // LOGSTORM_SINGLE_THREADED
file::~file() {
    stream << time() << log_entry << std::endl;
  /// Default destructor
  }
  #ifndef LOGSTORM_SINGLE_THREADED
}
    std::lock_guard<std::mutex> lock(output_mutex);
void file::log_fragment(std::string const &log_entry) {
  #endif // LOGSTORM_SINGLE_THREADED
  /// Log this fragment without ending the line
  stream.close();
  if(stream.good()) {
}
    #ifndef LOGSTORM_SINGLE_THREADED

      std::lock_guard<std::mutex> lock(output_mutex);
void file::log(std::string const &log_entry) {
    #endif // LOGSTORM_SINGLE_THREADED
  /// Log this line
    stream << log_entry;
  if(stream.good()) {
  }
    #ifndef LOGSTORM_SINGLE_THREADED
}
      std::lock_guard<std::mutex> lock(output_mutex);

    #endif // LOGSTORM_SINGLE_THREADED
}
    stream << time() << log_entry << std::endl;
}
  }
}
void file::log_fragment(std::string const &log_entry) {
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
