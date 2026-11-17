#ifndef ARCADE_SORTING_H
#define ARCADE_SORTING_H

#include <string>

#include "score_entry.h"

/// @file sorting.h
/// @brief Sorts and searches over arrays of ScoreEntry, with a comparison
/// counter.
///
/// Counting convention: add one to @p comparisons each time two elements are
/// compared by the Comparator, and each time two names are compared (with
/// ==, <, or compare()). Do not count loop-bound checks such as `i < count`.

/// Returns true when @p a belongs before @p b.
using Comparator = bool (*)(const ScoreEntry &, const ScoreEntry &);

/// Higher scores first. (Provided.)
bool score_descending(const ScoreEntry &a, const ScoreEntry &b);

/// Names in alphabetical order. (Provided.)
bool name_ascending(const ScoreEntry &a, const ScoreEntry &b);

/// Sort in place by repeatedly selecting the first element that belongs next.
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering
/// @param comparisons increased by the number of comparisons made
void selection_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons);

/// Sort in place by inserting each element into the sorted part before it.
/// Shift elements; do not swap.
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering
/// @param comparisons increased by the number of comparisons made
void insertion_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons);

/// Sort with merge sort. (Provided.) Uses a temporary array of the same size.
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering
/// @param comparisons increased by the number of comparisons made
void merge_sort(ScoreEntry *data, int count, Comparator before,
                long &comparisons);

/// Look for a name from the front.
/// @return the index of the first entry with that name, or -1
int linear_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons);

/// Look for a name by halving the range.
/// @pre @p data is sorted with name_ascending
/// @return the index of an entry with that name, or -1
int binary_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons);

#endif // ARCADE_SORTING_H
