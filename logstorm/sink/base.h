#ifndef LOGSTORM_SINK_BASE_H_INCLUDED
#define LOGSTORM_SINK_BASE_H_INCLUDED
#ifndef LOGSTORM_SINK_BASE_H_INCLUDED

#include <string>
#define LOGSTORM_SINK_BASE_H_INCLUDED
#include "logstorm/timestamp.h"


#include <string>
namespace logstorm {
#include "logstorm/timestamp.h"
namespace sink {


namespace logstorm {
class base {
namespace sink {
protected:

  timestamp time;
class base {

protected:
protected:
  timestamp time;
  explicit base(timestamp::types timestamp_type = timestamp::types::NONE);

public:
protected:
  virtual ~base() __attribute__((__const__));

  explicit base(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual void log(std::string const &log_entry) = 0;
public:
  virtual void log_fragment(std::string const &log_entry) = 0;
  virtual ~base() __attribute__((__const__));
};


  virtual void log(std::string const &log_entry) = 0;
}
  virtual void log_fragment(std::string const &log_entry) = 0;
}
};


#endif // LOGSTORM_SINK_BASE_H_INCLUDED
}
}

#endif // LOGSTORM_SINK_BASE_H_INCLUDED
