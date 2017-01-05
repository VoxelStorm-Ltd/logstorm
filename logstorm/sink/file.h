#ifndef LOGSTORM_SINK_file_H_INCLUDED
#ifndef LOGSTORM_SINK_file_H_INCLUDED
#define LOGSTORM_SINK_file_H_INCLUDED
#define LOGSTORM_SINK_file_H_INCLUDED


#include "base.h"
#include "base.h"
#include <fstream>
#include <fstream>
#ifndef LOGSTORM_SINGLE_THREADED
#ifndef LOGSTORM_SINGLE_THREADED
  #include <mutex>
  #include <mutex>
#endif // LOGSTORM_SINGLE_THREADED
#endif // LOGSTORM_SINGLE_THREADED
#include "logstorm/timestamp.h"

#include "logstorm/timestamp.h"
namespace logstorm {

namespace sink {
namespace logstorm {

namespace sink {
class file : public base {

  std::ofstream stream;
class file : public base {
  #ifndef LOGSTORM_SINGLE_THREADED
  std::ofstream stream;
    std::mutex output_mutex;
  #ifndef LOGSTORM_SINGLE_THREADED
  #endif // LOGSTORM_SINGLE_THREADED
    std::mutex output_mutex;

  #endif // LOGSTORM_SINGLE_THREADED
public:

  file(std::string const &target_filename, timestamp::types timestamp_type = timestamp::types::DATE_TIME);
public:
  virtual ~file();
  file(std::string const &target_filename, timestamp::types timestamp_type = timestamp::types::DATE_TIME);

  virtual ~file();
  virtual void log(std::string const &log_entry) override final;

  virtual void log_fragment(std::string const &log_entry) override final;
};
  virtual void log(std::string const &log_entry) override final;

  virtual void log_fragment(std::string const &log_entry) override final;
}
};
}


}
#endif // LOGSTORM_SINK_file_H_INCLUDED
}

#endif // LOGSTORM_SINK_file_H_INCLUDED
