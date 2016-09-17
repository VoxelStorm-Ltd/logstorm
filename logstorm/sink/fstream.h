}
#ifndef LOGSTORM_SINK_FSTREAM_H_INCLUDED
#define LOGSTORM_SINK_FSTREAM_H_INCLUDED

#include "base.h"
#include <fstream>
#include "logstorm/timestamp.h"

namespace logstorm {
namespace sink {

class fstream : public base {
private:
  std::ofstream &stream;

public:
  fstream(std::ofstream &target_stream, timestamp::types timestamp_type = timestamp::types::DATE_TIME);
  virtual ~fstream();

  virtual void log(std::string const &log_entry) override final;
  virtual void log_fragment(std::string const &log_entry) override final;
};

}
}

#endif // LOGSTORM_SINK_FSTREAM_H_INCLUDED
}

#endif // LOGSTORM_SINK_FSTREAM_H_INCLUDED
