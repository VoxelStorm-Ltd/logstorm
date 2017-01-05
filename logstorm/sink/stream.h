  std::ostream &ostream;
  #ifndef LOGSTORM_SINGLE_THREADED
    std::mutex output_mutex;
#ifndef LOGSTORM_SINK_STREAM_H_INCLUDED
  #endif // LOGSTORM_SINGLE_THREADED
#define LOGSTORM_SINK_STREAM_H_INCLUDED


public:
#include "base.h"
  stream(std::ostream &target_ostream, timestamp::types timestamp_type = timestamp::types::NONE);
#include <ostream>
  virtual ~stream() __attribute__((__const__));
#ifndef LOGSTORM_SINGLE_THREADED

  #include <mutex>
  virtual void log(std::string const &log_entry) override final;
#endif // LOGSTORM_SINGLE_THREADED
  virtual void log_fragment(std::string const &log_entry) override final;
#include "logstorm/timestamp.h"
};


}
namespace logstorm {
}
namespace sink {


#endif // LOGSTORM_SINK_STREAM_H_INCLUDED
class stream : public base {
  std::ostream &ostream;
  #ifndef LOGSTORM_SINGLE_THREADED
    std::mutex output_mutex;
  #endif // LOGSTORM_SINGLE_THREADED

public:
  stream(std::ostream &target_ostream, timestamp::types timestamp_type = timestamp::types::NONE);
  virtual ~stream() __attribute__((__const__));

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_STREAM_H_INCLUDED
