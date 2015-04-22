System Metadata
===============

In scientific software generating data, generally want an entire
provenance of how that data was produced. A wide range of metadata
will go into a provenance, and this mini project looks at techniques
to obtain metadata about the way in which a program is running.
This may include:

- How the program was built (compiler, flags etc)
- What libraries it loads at runtime
- What OS is it running on
- What CPU/Hardware is in use

These should generally be simple data like strings/integers so easy to
store. The issue is how to get them programatically in C/C++/Python,
and in a protable way (e.g. Linux, OSX, Windows).

