#ifndef LOGSTORM_SINK_CONSOLE_H_INCLUDED
#define LOGSTORM_SINK_CONSOLE_H_INCLUDED

#include "base.h"
#include "logstorm/timestamp.h"

namespace logstorm {
namespace sink {

class console : public base {
public:
  explicit console(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual ~console();

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_CONSOLE_H_INCLUDED
