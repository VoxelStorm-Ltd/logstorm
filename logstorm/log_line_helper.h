#ifndef LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
#define LOGSTORM_LOG_LINE_HELPER_H_INCLUDED

#include <vector>
#include <sstream>
#include <iostream>

namespace logstorm {

namespace sink {
class base;
}

class log_line_helper {
private:
  std::vector<sink::base*> &sinks;
  std::stringstream aggregator;

public:
  log_line_helper(std::vector<sink::base*> &sinks_to_use);
  ~log_line_helper();

  log_line_helper(log_line_helper const &other);

  template<typename T> log_line_helper &operator<<(T const &rhs) {
    /// Input operator forwarding to all sinks in string format
    aggregator << rhs;
    return *this;
  }
};

}

#endif // LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
