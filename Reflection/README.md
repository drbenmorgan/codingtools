Reflection with Ponder
======================
Some *very* simple tests of C++ reflection with [Ponder](https://github.com/billyquith/ponder).
Focus is on the existing use in the SuperNEMO experiment software with two main points:

- Minimal invasiveness (i.e. Ponder shouldn't affect/change core interfaces, and user shouldn't
need to instrument code more than needed).
- Minimal static initialization/usage (Ponder/reflection require some level of statics, but
don't rely on it nor require user to be careful of ordering).

The code in this example uses the basic `Person` example from upstream ponder as the reflected
class. The `Person` class is compiled into its own `libPerson` library without any Ponder
interfaces or linkage. A separate `Person_ponder` library/plugin is compiled that contains the
Ponder declarations for `Person` and its interface. This library uses a private function
and the `PONDER_AUTO_TYPE` macro to declare the `Person` class to Ponder. A second, `extern "C"`
function is used to "get" the class and trigger the registration, the `extern` allowing it to
be called after suitable `dlopen/dlsym` calls in a main program. This combination of functions
may be slight overkill and it may be possible to use only the declaration function for both
the declaration and load-at-runtime tasks.

A main program `basicPonder` is built to exercise the Ponder system and load the `Person_ponder`
"dictionary" (a deliberate naming for future contrast with ROOT's reflection system) plugin.
Running this program shows that loading the plugin results in the appropriate functionality is
loaded and made available. Note that the handling of the plugin is currently simplistic,
especially as regards error handling.

A second program `hiddenPonder` is built to demonstrate that with reflection only the Ponder
"dictionary" need be present to use the `Person` class (i.e. *no* knowledge of `Person`s
interface is needed via a class declaration).

The subdirectory `AutoStaticInit` contains a second example of using automatic execution of
declaration code using Boost.Serialization's special singletons. This is the technique used
in SuperNEMO at present but with a very high level of complexity. The example shows that this
can be significantly reduced. Decoupling the reflection layer from a main library reduces the
need for such a complex and fragile layer though, and plugin load/registration functions are
preferred for simplicity.
