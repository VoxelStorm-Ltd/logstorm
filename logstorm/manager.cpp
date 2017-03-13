#include "manager.h"
#include "cast_if_required.h"
#include "sink/base.h"

namespace logstorm {

manager::manager() {
  /// Default constructor
}

manager::~manager() {
  /// Default destructor
}

unsigned int manager::add_sink(std::shared_ptr<sink::base> newsink) {
  /// Add a logging sink, and return its id for later reference
  sinks.emplace_back(newsink);
  return cast_if_required<unsigned int>(sinks.size() - 1);
}
unsigned int manager::add_sink(sink::base *newsink) {
  return add_sink(std::shared_ptr<sink::base>(newsink));
}

std::shared_ptr<sink::base> manager::get_sink(unsigned int sink_id) {
  /// Fetch a logging sink by its id
  if(sink_id >= sinks.size()) {
    return nullptr;
  }
  return sinks[sink_id];
}

void manager::remove_sink(unsigned int sink_id) {
  /// Remove a logging sink by its id
  if(sink_id >= sinks.size()) {
    return;
  }
  sinks.erase(sinks.begin() + sink_id);
}

void manager::clear_sinks() {
  /// Remove all logging sinks
  sinks.clear();
}

void manager::log(std::string const &log_entry) {
  /// Log this line
  for(auto const &thissink : sinks) {
    thissink->log(log_entry);
  }
}

}
