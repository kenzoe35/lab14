#include <gtest/gtest.h>

#include <string>

#include "sorting.h"

namespace {

ScoreEntry entry(const std::string &name, int score) {
  return ScoreEntry{name, score, "test"};
}

bool is_sorted_by_score(const ScoreEntry *data, int count) {
  for (int i = 1; i < count; ++i) {
    if (data[i - 1].score < data[i].score) {
      return false;
    }
  }
  return true;
}

} // namespace

// ---- provided ---------------------------------------------------------------

TEST(SortingTest, SelectionSortPutsHighScoresFirst) {
  ScoreEntry data[5] = {entry("a", 30), entry("b", 90), entry("c", 10),
                        entry("d", 70), entry("e", 50)};
  long comparisons = 0;
  selection_sort(data, 5, score_descending, comparisons);
  EXPECT_TRUE(is_sorted_by_score(data, 5));
  EXPECT_EQ(data[0].name, "b");
  EXPECT_EQ(data[4].name, "c");
  EXPECT_EQ(comparisons, 10); // 5 * 4 / 2, whatever the input
}

TEST(SortingTest, LinearSearchFindsTheFirstMatchAndCounts) {
  const ScoreEntry data[4] = {entry("ann", 1), entry("bob", 2),
                              entry("cy", 3), entry("bob", 4)};
  long comparisons = 0;
  EXPECT_EQ(linear_search_name(data, 4, "bob", comparisons), 1);
  EXPECT_EQ(comparisons, 2);
  comparisons = 0;
  EXPECT_EQ(linear_search_name(data, 4, "zed", comparisons), -1);
  EXPECT_EQ(comparisons, 4);
}

// ---- yours: add two more here (Task 7) ------------------------------------
