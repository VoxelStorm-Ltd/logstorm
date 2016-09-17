#include "timestamp.h"

namespace logstorm {

timestamp::timestamp(types this_type)
  : type(this_type) {
}

timestamp::~timestamp() {
  /// Default destructor
}

}
