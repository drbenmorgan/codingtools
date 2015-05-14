CMakeComponentBuild
===================
Ideas for using CMake to build component-based projects. That is,
final build products are assembled from smaller components. Ideas
from ITK and Boost's CMake-ification.

Definitions
-----------
- A component is a small library
- A component is composed of public and private headers and source files
- A public header is an interface a client of the component may use
- A private header is an implementation detail of the component (i.e. a
  private interface).
- A component may use other components publically or privately.
- A component may use external libraries publically or privately.
- Public use of a component "A" by a component "B" means that public
  headers of "A" appear in public headers of "B"
- Private use of a component "A" by a component "B" means that public
  headers of "A" appear only in private headers and/or source files of "B"
- A product is an actual library output by the build process
- A product is composed of 1-N components
- A product has dependencies only via those declared by its components
- A component may not know which product it ends up in
- A component can only be a member of one product
- A component or product may be optional, but final DAG of dependencies
  must be closed.
- Optional components must be activated even if the user deactivates them
  if required by another active component.


Requirements
------------
- The name of a component must be definable
- A component shall declare its public headers, private headers and
  source files explicitely.
  - Motivation: In CMake, wish to avoid globbing so that builds are not
    inconsistent when sources are added or removed.
- A component shall declare any components it uses publically
- A component shall declare any components it uses privately
- A component shall declare any external libraries it uses publically
- A component shall declare any external libraries it uses privately
- A component shall declare any extra definitions it requires for compilation
- A product shall declare the component(s) that comprise it.

