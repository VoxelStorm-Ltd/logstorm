#ifndef LOGSTORM_H_INCLUDED
#define LOGSTORM_H_INCLUDED

/// Defines:
///   LOGSTORM_SINGLE_THREADED - Don't use synchronisation to protect sinks.
///   LOGSTORM_COMPOSE_FRAGMENTS_SEPARATELY - Don't append fragments with
///     log_fragment() to the current line, but store them until they receive
///     a std::endl() and then send the line as a whole.

#include "manager.h"
#include "sink/dummy.h"
#include "sink/stream.h"
#include "sink/console.h"
#include "sink/console_err.h"
#include "sink/fstream.h"
#include "sink/file.h"
#include "sink/circular_buffer.h"

#endif // LOGSTORM_H_INCLUDED
