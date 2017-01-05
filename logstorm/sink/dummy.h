#ifndef LOGSTORM_SINK_DUMMY_H_INCLUDED
#define LOGSTORM_SINK_DUMMY_H_INCLUDED
#ifndef LOGSTORM_SINK_DUMMY_H_INCLUDED

#include "base.h"
#define LOGSTORM_SINK_DUMMY_H_INCLUDED
#include "logstorm/timestamp.h"


#include "base.h"
namespace logstorm {
#include "logstorm/timestamp.h"
namespace sink {


namespace logstorm {
class dummy : public base {
namespace sink {
  /// Dummy logging class to not do anything (for use in a non-logging environment)

public:
class dummy : public base {
  explicit dummy(timestamp::types timestamp_type = timestamp::types::NONE);
  /// Dummy logging class to not do anything (for use in a non-logging environment)
  virtual ~dummy() __attribute__((__const__));

public:
  virtual void log(std::string const &log_entry) override final __attribute__((__const__));
  explicit dummy(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual void log_fragment(std::string const &log_entry) override final __attribute__((__const__));
  virtual ~dummy() __attribute__((__const__));
};


  virtual void log(std::string const &log_entry) override final __attribute__((__const__));
}
  virtual void log_fragment(std::string const &log_entry) override final __attribute__((__const__));
}
};


#endif // LOGSTORM_SINK_DUMMY_H_INCLUDED
}
}

#endif // LOGSTORM_SINK_DUMMY_H_INCLUDED
