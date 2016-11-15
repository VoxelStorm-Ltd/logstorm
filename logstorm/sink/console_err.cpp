#include "console_err.h"
#include <iostream>

namespace logstorm {
namespace sink {

console_err::console_err(timestamp::types timestamp_type)
  : base(timestamp_type) {
  /// Default constructor
}

console_err::~console_err() {
  /// Default destructor
}

void console_err::log(std::string const &log_entry) {
  /// Log this line
  #ifndef LOGSTORM_SINGLE_THREADED
    std::lock_guard<std::mutex> lock(output_mutex);
  #endif // LOGSTORM_SINGLE_THREADED
  std::cerr << time() << log_entry << std::endl;
}
void console_err::log_fragment(std::string const &log_entry) {
  /// Log this fragment without ending the line
  #ifndef LOGSTORM_SINGLE_THREADED
    std::lock_guard<std::mutex> lock(output_mutex);
  #endif // LOGSTORM_SINGLE_THREADED
  std::cerr << log_entry;
}

}
}
