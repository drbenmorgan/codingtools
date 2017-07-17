SimpleLogging
=============

Can we implement a Python-style logging interface in C++ and allow for
different logging implementations (e.g. spdlog, boost.log etc)?

Python-Style Logging
--------------------
The basic structure is outlined here:

- https://docs.python.org/2/howto/logging.html

In writing an *application*, then the typical pattern above works perfectly, as
do the typical patterns for C++ libraries. For *libraries* and also *plugins*,
then some care is needed to ensure this integrates with client applications.
In Python, a guide is located here:

- https://docs.python.org/2/howto/logging.html#library-config

with some recipes here:

- https://docs.python.org/2.7/howto/logging-cookbook.html

Python logging can be configured very easily from dictionaries
or config files:

- https://fangpenlin.com/posts/2012/08/26/good-logging-practice-in-python/

Note the basic pattern here:

- Formatters define output pattern
- Handlers determine endpoint/sink
- Loggers for modules must be defined, with parameters for
  - level of logging
  - what handler to use

This allows the top level application to configure the logging, and
modules simply to concern themselves with getting a logger instance
and logging to it. In particular, it means modules don't need to carry
around logging configuration.

Key(?) Things:

- User of a logger should not configure it, this is up to client
- "Configuration" can mean:
  - Log level (including whether to log or not)
  - What sink/handler to use.
  - Format of log messages.
- Use of named logger instances.
  - Enables the pattern of higher level configuration
  - Python makes this easy, less so in C++
- Basically, refer to how Python logging is configured!!
  - https://docs.python.org/2/library/logging.config.html

C++ Logging Packages
--------------------
- spdlog: https://github.com/gabime/spdlog
- Poco : https://pocoproject.org/slides/110-Logging.pdf
- log4cxx : https://logging.apache.org/log4cxx/latest_stable/
- Boost.Log : 

Backward/Forward Compatibility
------------------------------

Need to keep in mind the basic end-user interface:

- Get a logger : `getLogger("name") : LogObject&`
- Log a message : myLogger.info("log message");
- Log a message : myLogger.info() << "log message";
- Log a message : LOG_INFO(myLogger, "log something" << )


