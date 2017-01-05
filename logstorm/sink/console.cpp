#include <iostream>

namespace logstorm {
#include "console.h"
namespace sink {
#include <iostream>


console::console(timestamp::types timestamp_type)
namespace logstorm {
  : base(timestamp_type) {
namespace sink {
  /// Default constructor

}
console::console(timestamp::types timestamp_type)

  : base(timestamp_type) {
console::~console() {
  /// Default constructor
  /// Default destructor
}
}


console::~console() {
void console::log(std::string const &log_entry) {
  /// Default destructor
  /// Log this line
}
  #ifndef LOGSTORM_SINGLE_THREADED

    std::lock_guard<std::mutex> lock(output_mutex);
void console::log(std::string const &log_entry) {
  #endif // LOGSTORM_SINGLE_THREADED
  /// Log this line
  std::cout << time() << log_entry << std::endl;
  #ifndef LOGSTORM_SINGLE_THREADED
}
    std::lock_guard<std::mutex> lock(output_mutex);
void console::log_fragment(std::string const &log_entry) {
  #endif // LOGSTORM_SINGLE_THREADED
  /// Log this fragment without ending the line
  std::cout << time() << log_entry << std::endl;
  #ifndef LOGSTORM_SINGLE_THREADED
}
    std::lock_guard<std::mutex> lock(output_mutex);
  #endif // LOGSTORM_SINGLE_THREADED
void console::log_fragment(std::string const &log_entry) {
  std::cout << log_entry;
  /// Log this fragment without ending the line
}
  #ifndef LOGSTORM_SINGLE_THREADED

    std::lock_guard<std::mutex> lock(output_mutex);
}
  #endif // LOGSTORM_SINGLE_THREADED
}
  std::cout << log_entry;
}

}
}
