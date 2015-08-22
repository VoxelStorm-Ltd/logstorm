#ifndef LOGSTORM_SINK_file_H_INCLUDED
#define LOGSTORM_SINK_file_H_INCLUDED

#include "base.h"
#include <fstream>
#include "logstorm/timestamp.h"

namespace logstorm {
namespace sink {

class file : public base {
private:
  std::ofstream stream;

public:
  file(std::string const &target_filename, timestamp::types timestamp_type = timestamp::types::DATE_TIME);
  virtual ~file();

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_file_H_INCLUDED
