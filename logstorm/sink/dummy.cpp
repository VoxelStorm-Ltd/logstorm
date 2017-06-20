#include "dummy.h"

namespace logstorm::sink {

dummy::dummy(timestamp::types timestamp_type)
  : base(timestamp_type) {
  /// Default constructor
}

dummy::~dummy() {
  /// Default destructor
}

void dummy::log(std::string const &log_entry __attribute__((__unused__))) {
  /// Dummy function to not do anything (for use in a non-logging environment)
}
void dummy::log_fragment(std::string const &log_entry __attribute__((__unused__))) {
  /// Dummy function to not do anything (for use in a non-logging environment)
}

}
