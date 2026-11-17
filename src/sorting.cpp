#include "sorting.h"

bool score_descending(const ScoreEntry &a, const ScoreEntry &b) {
  return a.score > b.score;
}

bool name_ascending(const ScoreEntry &a, const ScoreEntry &b) {
  return a.name < b.name;
}

// ---- merge sort (provided) -------------------------------------------------

namespace {

/// Merge data[low..mid) and data[mid..high) into one sorted run, using
/// scratch as temporary space. Takes from the left run unless the right
/// element strictly belongs first, which keeps equal elements in order.
void merge_runs(ScoreEntry *data, ScoreEntry *scratch, int low, int mid,
                int high, Comparator before, long &comparisons) {
  int left = low;
  int right = mid;
  int out = low;
  while (left < mid && right < high) {
    ++comparisons;
    if (before(data[right], data[left])) {
      scratch[out++] = data[right++];
    } else {
      scratch[out++] = data[left++];
    }
  }
  while (left < mid) {
    scratch[out++] = data[left++];
  }
  while (right < high) {
    scratch[out++] = data[right++];
  }
  for (int i = low; i < high; ++i) {
    data[i] = scratch[i];
  }
}

void merge_sort_range(ScoreEntry *data, ScoreEntry *scratch, int low, int high,
                      Comparator before, long &comparisons) {
  if (high - low < 2) {
    return;
  }
  const int mid = low + (high - low) / 2;
  merge_sort_range(data, scratch, low, mid, before, comparisons);
  merge_sort_range(data, scratch, mid, high, before, comparisons);
  merge_runs(data, scratch, low, mid, high, before, comparisons);
}

} // namespace

void merge_sort(ScoreEntry *data, int count, Comparator before,
                long &comparisons) {
  if (count < 2) {
    return;
  }
  ScoreEntry *scratch = new ScoreEntry[count];
  merge_sort_range(data, scratch, 0, count, before, comparisons);
  delete[] scratch;
}

// ---- yours (Lab 14) --------------------------------------------------------
// Each function below is a stub so the program builds. Replace the bodies.
// Counting convention: see sorting.h.

void selection_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons) {
  // TODO (Task 2)
  (void)data;
  (void)count;
  (void)before;
  (void)comparisons;
}

void insertion_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons) {
  // TODO (Task 5): shift elements; do not swap.
  (void)data;
  (void)count;
  (void)before;
  (void)comparisons;
}

int linear_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
  // TODO (Task 2)
  (void)data;
  (void)count;
  (void)name;
  (void)comparisons;
  return -1;
}

int binary_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
  // TODO (Task 3)
  (void)data;
  (void)count;
  (void)name;
  (void)comparisons;
  return -1;
}
