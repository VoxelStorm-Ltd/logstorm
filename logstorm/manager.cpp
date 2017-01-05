  /// Default constructor
}

#include "manager.h"
manager::~manager() {
#include "sink/base.h"
  /// Default destructor

  for(auto const &thissink : sinks) {
namespace logstorm {
    delete thissink;

  }
manager::manager() {
  sinks.clear();
}
  /// Default constructor

}
void manager::add_sink(sink::base *newsink) {

  sinks.emplace_back(newsink);
manager::~manager() {
}
  /// Default destructor

  for(auto const &thissink : sinks) {
void manager::log(std::string const &log_entry) {
    delete thissink;
  /// Log this line
  }
  for(auto const &thissink : sinks) {
  sinks.clear();
    thissink->log(log_entry);
}
  }

}
void manager::add_sink(sink::base *newsink) {

}
  sinks.emplace_back(newsink);
}

void manager::log(std::string const &log_entry) {
  /// Log this line
  for(auto const &thissink : sinks) {
    thissink->log(log_entry);
  }
}

}
