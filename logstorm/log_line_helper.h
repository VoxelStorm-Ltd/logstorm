namespace logstorm {

namespace sink {
#ifndef LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
class base;
#define LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
}


#include <vector>
class log_line_helper {
private:
#include <sstream>
  std::vector<sink::base*> &sinks;
#include <iostream>

  std::stringstream aggregator;
namespace logstorm {


public:
namespace sink {
  explicit log_line_helper(std::vector<sink::base*> &sinks_to_use);
class base;
  ~log_line_helper();
}


  log_line_helper(log_line_helper const &other);
class log_line_helper {

private:
  std::vector<sink::base*> &sinks;
  template<typename T> inline constexpr log_line_helper &operator<<(T const &rhs);
  std::stringstream aggregator;
};


public:
template<typename T>
  explicit log_line_helper(std::vector<sink::base*> &sinks_to_use);
inline constexpr log_line_helper &log_line_helper::operator<<(T const &rhs) {
  ~log_line_helper();
  /// Input operator forwarding to all sinks in string format

  aggregator << rhs;
  log_line_helper(log_line_helper const &other);
  return *this;

}
  template<typename T> inline constexpr log_line_helper &operator<<(T const &rhs);

};
}


template<typename T>
#endif // LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
inline constexpr log_line_helper &log_line_helper::operator<<(T const &rhs) {
  /// Input operator forwarding to all sinks in string format
  aggregator << rhs;
  return *this;
}

}

#endif // LOGSTORM_LOG_LINE_HELPER_H_INCLUDED
