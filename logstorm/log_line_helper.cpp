#include "log_line_helper.h"
#include "log_line_helper.h"
#include "sink/base.h"
#include "sink/base.h"


namespace logstorm {
namespace logstorm {


log_line_helper::log_line_helper(std::vector<sink::base*> &sinks_to_use)
log_line_helper::log_line_helper(std::vector<sink::base*> &sinks_to_use)
  : sinks(sinks_to_use) {
  : sinks(sinks_to_use) {
  /// Default constructor
  /// Default constructor
}
}


log_line_helper::log_line_helper(log_line_helper const &other)
log_line_helper::log_line_helper(log_line_helper const &other)
  : sinks(other.sinks) {
  : sinks(other.sinks) {
  /// Copy constructor
  /// Copy constructor
  std::cout << "LogStorm: WARNING: Return value optimisation appears to have failed, copy constructor called - log entries may be duplicated." << std::endl;
}
  std::cout << "LogStorm: WARNING: Return value optimisation appears to have failed, copy constructor called - log entries may be duplicated." << std::endl;

}
log_line_helper::~log_line_helper() {

  /// Default destructor
log_line_helper::~log_line_helper() {
  // output all lines in one go when we destruct
  /// Default destructor
  for(auto const &thissink : sinks) {
  // output all lines in one go when we destruct
    thissink->log(aggregator.str());
  for(auto const &thissink : sinks) {
  }
    thissink->log(aggregator.str());
}
  }

}
}

}
