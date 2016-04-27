#ifndef LOGSTORM_SINK_DUMMY_H_INCLUDED
#define LOGSTORM_SINK_DUMMY_H_INCLUDED

#include "base.h"
#include "logstorm/timestamp.h"

namespace logstorm {
namespace sink {

class dummy : public base {
  /// Dummy logging class to not do anything (for use in a non-logging environment)
public:
  explicit dummy(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual ~dummy();

  virtual void log(std::string const &log_entry) override final __attribute__((__const__));
  virtual void log_fragment(std::string const &log_entry) override final __attribute__((__const__));
};

}
}

#endif // LOGSTORM_SINK_DUMMY_H_INCLUDED
