# LogStorm
C++ logging library by VoxelStorm.

A simple templated multi-sink logger with optional thread safety.  Designed to make it easy and compact to log text to console and file, and to easily be extensible to receive other sources.

## Usage

```cpp
#include <logstorm/logstorm.h>

logstorm::manager logger;
logger.add_sink(new logstorm::sink::console);
logger.add_sink(new logstorm::sink::file("myfile.log", logstorm::timestamp::types::SINCE_START)));

// different ways to log:
logger.log("hello world");
logger("hello world");
logger("hello ", "world ", 1234);
logger << "Hello world! " << 1234;   // note: newline is added automagically
```

You can add as many sources of the same type as you like, so you can log to multiple files, streams, etc.

The default behaviour is to append the appropriate end and flush fragment for each stream at the end of the statement, so manually suffixing with `'\n'` or `std::endl` is not necessary.  You can override this, as shown below.

## Configuration

The following compile-time switches are available - define:
- LOGSTORM_SINGLE_THREADED - Don't use synchronisation to protect sinks.
- LOGSTORM_COMPOSE_FRAGMENTS_SEPARATELY - Don't append fragments with `log_fragment()` to the current line, but store them until they receive a `std::endl()` and then send the line as a whole.
