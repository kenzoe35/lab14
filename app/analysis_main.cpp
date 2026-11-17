/// @file analysis_main.cpp
/// @brief Counts the comparisons each sort makes, for ANALYSIS.md.
///
/// Every sort orders the entries with score_descending. So "ascending" input
/// (1, 2, 3, ...) is the reverse of the order the sort wants, and
/// "descending" input (n, ..., 2, 1) is already in order.

#include <iomanip>
#include <iostream>
#include <random>

#include "sorting.h"

namespace {

enum class Input { random, ascending, descending };

const char *input_name(Input input) {
  switch (input) {
  case Input::random:
    return "random";
  case Input::ascending:
    return "ascending (reverse of wanted order)";
  case Input::descending:
    return "descending (already in order)";
  }
  return "";
}

void fill(ScoreEntry *data, int count, Input input, std::mt19937 &gen) {
  for (int i = 0; i < count; ++i) {
    data[i] = ScoreEntry{"player" + std::to_string(i), i + 1, "test"};
  }
  if (input == Input::descending) {
    for (int i = 0; i < count; ++i) {
      data[i].score = count - i;
    }
  } else if (input == Input::random) {
    // Fisher-Yates shuffle of the scores.
    for (int i = count - 1; i > 0; --i) {
      std::uniform_int_distribution<int> pick{0, i};
      const int j = pick(gen);
      const int held = data[i].score;
      data[i].score = data[j].score;
      data[j].score = held;
    }
  }
}

} // namespace

int main() {
  std::mt19937 gen{1437}; // fixed seed: everyone gets the same random input
  const int sizes[3] = {10, 100, 1000};
  const Input inputs[3] = {Input::random, Input::ascending, Input::descending};

  std::cout << std::left << std::setw(40) << "input" << std::right
            << std::setw(8) << "n" << std::setw(12) << "selection"
            << std::setw(12) << "insertion" << std::setw(12) << "merge"
            << "\n";
  for (Input input : inputs) {
    for (int n : sizes) {
      long counts[3] = {0, 0, 0};
      ScoreEntry *original = new ScoreEntry[n];
      ScoreEntry *work = new ScoreEntry[n];
      fill(original, n, input, gen);

      for (int i = 0; i < n; ++i) {
        work[i] = original[i];
      }
      selection_sort(work, n, score_descending, counts[0]);
      for (int i = 0; i < n; ++i) {
        work[i] = original[i];
      }
      insertion_sort(work, n, score_descending, counts[1]);
      for (int i = 0; i < n; ++i) {
        work[i] = original[i];
      }
      merge_sort(work, n, score_descending, counts[2]);

      std::cout << std::left << std::setw(40) << input_name(input)
                << std::right << std::setw(8) << n << std::setw(12)
                << counts[0] << std::setw(12) << counts[1] << std::setw(12)
                << counts[2] << "\n";
      delete[] original;
      delete[] work;
    }
  }
  return 0;
}
