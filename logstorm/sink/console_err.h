
class console_err : public base {
  #ifndef LOGSTORM_SINGLE_THREADED
#ifndef LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
    std::mutex output_mutex;
#define LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
  #endif // LOGSTORM_SINGLE_THREADED


#include "base.h"
public:
#ifndef LOGSTORM_SINGLE_THREADED
  explicit console_err(timestamp::types timestamp_type = timestamp::types::NONE);
  #include <mutex>
  virtual ~console_err() __attribute__((__const__));
#endif // LOGSTORM_SINGLE_THREADED

#include "logstorm/timestamp.h"
  virtual void log(std::string const &log_entry) override final;

  virtual void log_fragment(std::string const &log_entry) override final;
namespace logstorm {
};
namespace sink {


}
class console_err : public base {
}
  #ifndef LOGSTORM_SINGLE_THREADED

    std::mutex output_mutex;
#endif // LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
  #endif // LOGSTORM_SINGLE_THREADED

public:
  explicit console_err(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual ~console_err() __attribute__((__const__));

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_CONSOLE_ERR_H_INCLUDED
