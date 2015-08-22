#include "manager.h"
#include "sink/base.h"

namespace logstorm {

manager::manager() {
  /// Default constructor
}

manager::~manager() {
  /// Default destructor
  for(auto const &thissink : sinks) {
    delete thissink;
  }
  sinks.clear();
}

void manager::add_sink(sink::base *newsink) {
  sinks.emplace_back(newsink);
}

void manager::log(std::string const &log_entry) {
  /// Log this line
  for(auto const &thissink : sinks) {
    thissink->log(log_entry);
  }
}

}
