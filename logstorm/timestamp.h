    SINCE_START
  } type = types::DEFAULT;
#ifndef LOGSTORM_TIMESTAMP_H_INCLUDED

  std::string operator()() {
#define LOGSTORM_TIMESTAMP_H_INCLUDED
    /// Generate a timestamp as appropriate to this timestamp's type

    switch(type) {
#include <chrono>
    default:
#include <iomanip>
    case types::DEFAULT:

    case types::NONE:
namespace logstorm {
      return "";

    case types::TIME:
class timestamp {
      {
  std::chrono::time_point<std::chrono::system_clock> time_start = std::chrono::system_clock::now();
        std::time_t time = std::time(nullptr);
public:
        std::stringstream ss;
  enum class types {
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d ");
    DEFAULT,
        return ss.str();
      }
    case types::DATE:
      {
        std::time_t time = std::time(nullptr);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%H:%M:%S ");
        return ss.str();
      }
    case types::DATE_TIME:
      {
        std::time_t time = std::time(nullptr);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S ");
        return ss.str();
      }
    case types::UNIX:
      {
        std::stringstream ss;
        ss << std::time(nullptr) << " ";
        return ss.str();
      }
    case types::SINCE_START:
      {
        // give time in seconds to two decimal places
        std::chrono::duration<float> const time_elapsed = std::chrono::system_clock::now() - time_start;
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << time_elapsed.count() << " ";
        return ss.str();
      }
    }
  }

  explicit timestamp(types this_type = types::NONE);
  ~timestamp() __attribute__((__const__));
};

}

#endif // LOGSTORM_TIMESTAMP_H_INCLUDED
