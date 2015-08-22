#include "console.h"
#include <iostream>

namespace logstorm {
namespace sink {

console::console(timestamp::types timestamp_type)
  : base(timestamp_type) {
  /// Default constructor
}

console::~console() {
  /// Default destructor
}

void console::log(std::string const &log_entry) {
  /// Log this line
  std::cout << time() << log_entry << std::endl;
}
void console::log_fragment(std::string const &log_entry) {
  /// Log this fragment without ending the line
  std::cout << log_entry;
}

}
}
