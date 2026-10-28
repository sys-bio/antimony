# Antimony Julia bindings

A pure-Julia package that calls libAntimony through its C API. Enable it with `-DWITH_JULIA=ON`.

The package is installed to `<prefix>/bindings/julia/Antimony`, with a copy of the library in its `lib` folder, so the folder can be moved or zipped on its own.
CI uploads it as the `antimony-julia-<platform>` artifact. The package is platform-specific because of the library it carries.

```julia
using Pkg
Pkg.develop(path="<prefix>/bindings/julia/Antimony")

using Antimony
Antimony.loadAntimonyString("model m; S1 -> S2; k1*S1; S1 = 10; k1 = 0.5; end")
sbml = Antimony.getSBMLString("m")
```

To use a different copy of the library, set the `ANTIMONY_LIBRARY` environment variable to its full path.

Tests are registered with CTest as `julia_antimony_bindings` (label `julia`) when `WITH_GTEST` is on and `julia` is on the path.
