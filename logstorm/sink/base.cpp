#include "base.h"

namespace logstorm {
namespace sink {

base::base(timestamp::types timestamp_type)
  : time(timestamp_type) {
  /// Default constructor
}

base::~base() {
  /// Default destructor
}

}
}
