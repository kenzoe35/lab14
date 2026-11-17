# Arcade: Week 14 starter (S14)

A text-game arcade in C++20. This is the starting point for **Lab 14: Searching and Sorting**. It is your Lab 13 solution (abstract `Game`, `Arcade`, monsters) plus a leaderboard that depends on four functions you write.

## What is already here

| Part | Files | Notes |
| --- | --- | --- |
| Arcade (finished) | `arcade.*`, `game.*`, the four games | After each game the arcade asks for a name, records the score, and has an **H. High Scores** option |
| Data and declarations | `include/score_entry.h`, `include/sorting.h` | `ScoreEntry`, `Comparator`, and all six sort and search signatures |
| **Sorting** | `src/sorting.cpp` | `merge_sort` and its helpers are written. **The four functions you write are stubs.** |
| Leaderboard | `leaderboard.*` | Finished. It calls your functions, so High Scores works when they pass their tests. |
| Analysis harness | `app/analysis_main.cpp` | Sizes 10, 100, 1000; random, ascending, descending input; all three sorts |
| Tests | `tests/test_sorting.cpp` | Two provided tests. You add two more. |
| Notes to fill in | `ANALYSIS.md`, `GDB_LOG.md` | |

## Expect failing tests at first

The four stubs do nothing, so the provided tests fail until you write them. Failing tests are your to-do list. Everything else builds and the rest of the tests pass.

## Build and run

```
cmake -S . -B build
cmake --build build
./build/arcade
cmake --build build --target analysis_main
./build/analysis_main
cd build && ctest --output-on-failure
```

AddressSanitizer, in a separate folder: `cmake -S . -B build-asan -DENABLE_ASAN=ON`.

## Counting convention

Add one to `comparisons` each time two elements are compared by the `Comparator`, and each time two names are compared (with `==`, `<`, or `compare()`). Do not count loop-bound checks such as `i < count`. The `Comparator` returns true when `a` belongs **before** `b`.

## Rules

- No warnings under `-Wall -Wextra`.
- Allowed headers: `<iostream>`, `<iomanip>`, `<string>`, `<fstream>`, `<stdexcept>`, `<random>`. No standard containers, no `<algorithm>`, no `using namespace std;`.
- Naming: `underscore_separated` functions and variables, `Capitalized` types, private data members start with `m_`, enumerators are lowercase, no ALL_CAPS constants.
- Conventional Commits, composed in the editor (not `-m`). One repository per pair; both partners commit.
