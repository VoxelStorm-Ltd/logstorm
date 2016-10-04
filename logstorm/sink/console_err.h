#ifndef LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
#define LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED

#include "base.h"
#include "logstorm/timestamp.h"

namespace logstorm {
namespace sink {

class console_err : public base {
public:
  explicit console_err(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual ~console_err() __attribute__((__const__));

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
