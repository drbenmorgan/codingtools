FileID
======

Test using libmagic (and possibly others) for file id. Idea is for
this to act under the hood of a "`FileReaderFactory`" object so that
the correct concrete reader type can be created.

libmagic at least seems to include id for ROOT files.

