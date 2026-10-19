# c-algorithms

A small library of generic data structures and classic algorithms (sorting, searching, optimization) written in strict C11, build while reading *Introduction to Algorithms* by Cormen. Elements are type-erased (`void *`) and driven by pluggable `Compare` and `Operations` function tables, with defaults for `int` and `double`.

## Running

**Requirements:** a C compiler, [CMake](https://cmake.org) >= 3.25 and [Ninja](https://ninja-build.org). A Nix flake (`flake.nix`) provides everything (`nix develop`, or `direnv allow`).

- **With the script:**

```sh
./tools/run.sh          # build and run the example (default)
./tools/run.sh build    # only build
./tools/run.sh test     # build and run the tests
./tools/run.sh debug    # build and open gdb (uses gdbserver inside tmux)
```

Short forms are also accepted: `r`, `b`, `t`, `d`.

- **Without the script:**

```sh
cmake --workflow --preset dev    # configure + build (Debug)
cmake --workflow --preset test   # configure + build + run tests
./build/debug/examples/compare_example
```

Other presets: `analyse` (builds with clang-tidy) and `ship` (Release). Documentation can be generated with `doxygen`.

## Project structure

```
.
├── libs
│   ├── algorithms/         # Sort and search algorithms
│   ├── data_structures/    # List and ListView
│   ├── compare/            # Generic comparison (Compare, CompareFunc)
│   ├── operations/         # Generic arithmetic (add, subtract, multiply, divide)
│   └── utils/              # Assertions, checked allocation, memory helpers
├── tests/                  # Unit tests (Unity), one folder per library
├── examples/
├── cmake/
└── tools/
```

## AI usage

AI is used only as a Socratic tutor: it reviews reasoning (loop invariants, complexity, edge cases, C safety) and asks questions, but does not write the solutions. The algorithms, proofs and code in this repository are written by me. The tutor rules are in `.clinerules`.
