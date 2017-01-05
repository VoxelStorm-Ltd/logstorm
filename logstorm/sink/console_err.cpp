#include "console_err.h"
#include "console_err.h"
#include <iostream>
#include <iostream>


namespace logstorm {
namespace logstorm {
namespace sink {
namespace sink {


console_err::console_err(timestamp::types timestamp_type)
console_err::console_err(timestamp::types timestamp_type)
  : base(timestamp_type) {
  : base(timestamp_type) {
  /// Default constructor
  /// Default constructor
}
}


console_err::~console_err() {
console_err::~console_err() {
  /// Default destructor
}
  /// Default destructor

}
void console_err::log(std::string const &log_entry) {

  /// Log this line
void console_err::log(std::string const &log_entry) {
  #ifndef LOGSTORM_SINGLE_THREADED
  /// Log this line
    std::lock_guard<std::mutex> lock(output_mutex);
  #ifndef LOGSTORM_SINGLE_THREADED
  #endif // LOGSTORM_SINGLE_THREADED
    std::lock_guard<std::mutex> lock(output_mutex);
  std::cerr << time() << log_entry << std::endl;
  #endif // LOGSTORM_SINGLE_THREADED
}
  std::cerr << time() << log_entry << std::endl;
void console_err::log_fragment(std::string const &log_entry) {
}
  /// Log this fragment without ending the line
void console_err::log_fragment(std::string const &log_entry) {
  #ifndef LOGSTORM_SINGLE_THREADED
  /// Log this fragment without ending the line
    std::lock_guard<std::mutex> lock(output_mutex);
  #ifndef LOGSTORM_SINGLE_THREADED
  #endif // LOGSTORM_SINGLE_THREADED
  std::cerr << log_entry;
    std::lock_guard<std::mutex> lock(output_mutex);
}
  #endif // LOGSTORM_SINGLE_THREADED

  std::cerr << log_entry;
}
}
}

}
}
