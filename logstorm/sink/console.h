#ifndef LOGSTORM_SINK_CONSOLE_H_INCLUDED
#define LOGSTORM_SINK_CONSOLE_H_INCLUDED
#ifndef LOGSTORM_SINK_CONSOLE_H_INCLUDED

#include "base.h"
#define LOGSTORM_SINK_CONSOLE_H_INCLUDED
#ifndef LOGSTORM_SINGLE_THREADED

  #include <mutex>
#include "base.h"
#endif // LOGSTORM_SINGLE_THREADED
#ifndef LOGSTORM_SINGLE_THREADED
#include "logstorm/timestamp.h"
  #include <mutex>

#endif // LOGSTORM_SINGLE_THREADED
namespace logstorm {
#include "logstorm/timestamp.h"
namespace sink {


namespace logstorm {
class console : public base {
namespace sink {
  #ifndef LOGSTORM_SINGLE_THREADED

    std::mutex output_mutex;
class console : public base {
  #endif // LOGSTORM_SINGLE_THREADED

  #ifndef LOGSTORM_SINGLE_THREADED
public:
    std::mutex output_mutex;
  explicit console(timestamp::types timestamp_type = timestamp::types::NONE);
  #endif // LOGSTORM_SINGLE_THREADED
  virtual ~console() __attribute__((__const__));


public:
  virtual void log(std::string const &log_entry) override final;
  explicit console(timestamp::types timestamp_type = timestamp::types::NONE);
  virtual void log_fragment(std::string const &log_entry) override final;
  virtual ~console() __attribute__((__const__));
};


  virtual void log(std::string const &log_entry) override final;
}
  virtual void log_fragment(std::string const &log_entry) override final;
}

};
#endif // LOGSTORM_SINK_CONSOLE_H_INCLUDED

}
}

#endif // LOGSTORM_SINK_CONSOLE_H_INCLUDED
