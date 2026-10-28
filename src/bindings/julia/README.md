# Antimony Julia bindings

A pure-Julia package that calls libAntimony through its C API.

## Installing a prebuilt package

1. Download the `antimony-julia-<platform>` asset for your system from the [Antimony releases](https://github.com/sys-bio/antimony/releases): `windows-latest`, `macos-14` (Apple silicon), `macos-15-intel`, `manylinux_2_28` or `ubuntu-latest`. The package is platform-specific because it carries the library.
2. Unzip it to get an `Antimony` folder, and leave that folder where you want to use it from.
3. In Julia (1.6 or newer):

```julia
using Pkg
Pkg.develop(path="/path/to/Antimony")

using Antimony
Antimony.loadAntimonyString("model m; S1 -> S2; k1*S1; S1 = 10; k1 = 0.5; end")
sbml = Antimony.getSBMLString("m")
```

## Building from source

Configure Antimony with `-DWITH_JULIA=ON`. After installing, the package is in `<prefix>/bindings/julia/Antimony`, with a copy of the library in its `lib` folder, so the folder can be moved or zipped on its own. Use it with `Pkg.develop` as above. The releases contain that folder as the `antimony-julia-<platform>` artifacts.

To use a different copy of the library, set the `ANTIMONY_LIBRARY` environment variable to its full path.

Tests are registered with CTest as `julia_antimony_bindings` (label `julia`) when `WITH_GTEST` is on and `julia` is on the path.
