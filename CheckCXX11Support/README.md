CheckCXX11Support
=================
Test ability of CMake to detect support for C++11 features by the compiler
and/or standard library.

The baseline tests are taken from the `cmake-cxx11` repository:

git://anongit.kde.org/scratch/dakon/cmake-cxx11.git

which is also [viewable online](http://quickgit.kde.org/?p=scratch%2Fdakon%2Fcmake-cxx11.git)

Additional tests have been added to determine support for further aspects
of the standard. These are still a work in progress, so may not work
perfectly on every combination of compiler and standard library.

How to Use
==========
Simply run `cmake` (2.8.3 or better), pointing it the directory in which
this README resides.
Though an out-of-source build is not enforced, it is strongly recommended that
you use a separate directory for builds so that multiple compilers/versions
can be tested.

The CMake step will try to compile and run test programs, each exercising
a feture of the C++11 standard (note that some features also have checks
for compilation and runtime failures). CMake will report the running and
  result of each feature test.
  For each feature tested, an internal
cache variable is set to indicate the availability of support for that
feature under the current build configuration. A complete list of these
variables can be found in CMake/cmake-cxx11/Modules/CheckCXX11Features.cmake.

At present, there is nothing to do beyond the CMake step as no programs
are built! However, an example header template, `example_header.hpp.in` is
provided that demonstrates the use of the cache variables to set
preprocessor directives indicating support of each feature.

FNAL CPP0X Checks
=================
The FNAL [cpp0x](https://cdcvs.fnal.gov/redmine/projects/cpp0x) package
checks many C++11 features at compile time, but these are locked
to the GCC version detected. We'd like to reproduce the checks here. Some
will be already present in `cmake-cxx11` but others will be needed.

The complete list of defines used by `cpp0x` are listed below, and
will be updated as support in the `CheckCXX11Features` tests are identified
and matched.

```cpp
// --- Initially assume _no_ C++0X core features are implemented:
// -> "HAS_CXX11_AUTO" #undef CPP0X_HAS_AUTO
#undef CPP0X_HAS_CONSTEXPR_FUNCTIONS
#undef CPP0X_HAS_CONSTEXPR_VARIABLES
// -> "HAS_CXX11_DECLTYPE" #undef CPP0X_HAS_DECLTYPE
#undef CPP0X_HAS_EXPLICIT_CONVERSION_OPERATORS
// -> "HAS_CXX11_DEFAULT_TEMPLATE_ARGUMENTS #undef CPP0X_HAS_FCTN_TEMPLATE_DEFAULT_ARGS
// -> "HAS_CXX11_LAMBDA" #undef CPP0X_HAS_LAMBDAS
// -> "HAS_CXX11_NOEXCEPT" #undef CPP0X_HAS_NOEXCEPT
// -> "HAS_CXX11_NULLPTR" #undef CPP0X_HAS_NULLPTR
// -> "HAS_CXX11_RVALUE_REFERENCES" #undef CPP0X_HAS_RVALUE_REFERENCES
// -> "HAS_CXX11_STATIC_ASSERT" #undef CPP0X_HAS_STATIC_ASSERT
// -> "HAS_CXX11_VARIADIC_TEMPLATES" #undef CPP0X_HAS_VARIADIC_TEMPLATES

// --- Initially assume _no_ C++0X library features are implemented:
// -> "HAS_CXX11_ALGORITHM_ALL_OF" #undef CPP0X_HAS_ALGORITHM_ALL_OF
// -> "HAS_CXX11_ALGORITHM_ANY_OF" #undef CPP0X_HAS_ALGORITHM_ANY_OF
// -> "HAS_CXX11_ALGORITHM_COPY_N" #undef CPP0X_HAS_ALGORITHM_COPY_N
// -> "HAS_CXX11_ALGORITHM_FIND_IF_NOT #undef CPP0X_HAS_ALGORITHM_FIND_IF_NOT
// -> "HAS_CXX11_ALGORITHM_IS_PARTITIONED" #undef CPP0X_HAS_ALGORITHM_IS_PARTITIONED
// -> "HAS_CXX11_ALGORITHM_IS_SORTED" #undef CPP0X_HAS_ALGORITHM_IS_SORTED
// -> "HAS_CXX11_ALGORITHM_MIN_MAX" #undef CPP0X_HAS_ALGORITHM_MIN_MAX
// -> "HAS_CXX11_ALGORITHM_NONE_OF" #undef CPP0X_HAS_ALGORITHM_NONE_OF
// -> "HAS_CXX11_PARTITION_POINT" #undef CPP0X_HAS_ALGORITHM_PARTITION_POINT
// -> "HAS_CXX11_ALGORITHM_SHUFFLE" #undef CPP0X_HAS_ALGORITHM_SHUFFLE
// -> "HAS_CXX11_ARRAY" #undef CPP0X_HAS_ARRAY_HDR
#undef CPP0X_HAS_CMATH_C99
// -> "HAS_CXX11_CMATH_FPCLASSIFY" #undef CPP0X_HAS_CMATH_FPCLASSIFICATION
// -> "HAS_CXX11_CSTDDEF_NULLPTR_T" #undef CPP0X_HAS_CSTDDEF_NULLPTR_T
// -> "HAS_CXX11_CSTDINT_H" #undef CPP0X_HAS_CSTDINT_HDR
#undef CPP0X_HAS_FUNCTIONAL_BIND
#undef CPP0X_HAS_FUNCTIONAL_FUNCTION
#undef CPP0X_HAS_FUNCTIONAL_HASH
#undef CPP0X_HAS_FUNCTIONAL_MEM_FN
#undef CPP0X_HAS_FUNCTIONAL_REFERENCE_WRAPPER
// -> "HAS_CXX11_RANGE_BASED_FOR" #undef CPP0X_HAS_ITERATOR_RANGE
// -> "HAS_CXX11_MEMORY_SHARED_PTR" #undef CPP0X_HAS_MEMORY_SHARED_PTR
// -> "HAS_CXX11_MEMORY_UNIQUE_PTR" #undef CPP0X_HAS_MEMORY_UNIQUE_PTR
// -> "HAS_CXX11_NUMERIC_IOTA" #undef CPP0X_HAS_NUMERIC_IOTA
#undef CPP0X_HAS_RANDOM_HDR
// -> "HAS_CXX11_LIB_REGEX" #undef CPP0X_HAS_REGEX_HDR
// -> "HAS_CXX11_STRING_NUMERIC_CONVERSIONS" #undef CPP0X_HAS_STRING_NUMERIC_CONVERSIONS
// -> "HAS_CXX11_SYSTEM_ERROR" #undef CPP0X_HAS_SYSTEM_ERROR_HDR
// -> "HAS_CXX11_TUPLE" #undef CPP0X_HAS_TUPLE_HDR
// -> "HAS_CXX11_TYPE_TRAITS" #undef CPP0X_HAS_TYPE_TRAITS_HDR
// -> "HAS_CXX11_UTILITY_DECLVAL" #undef CPP0X_HAS_UTILITY_DECLVAL
```

As time goes on, we'll match these against tests we already have and add
additional functionality.

