#ifndef LOGSTORM_H_INCLUDED
#define LOGSTORM_H_INCLUDED

/// Defines:
///   LOGSTORM_SINGLE_THREADED - don't use synchronisation to protect sinks

#include "manager.h"
#include "sink/dummy.h"
#include "sink/stream.h"
#include "sink/console.h"
#include "sink/console_err.h"
#include "sink/fstream.h"
#include "sink/file.h"

#endif // LOGSTORM_H_INCLUDED
