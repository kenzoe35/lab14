#ifndef ARCADE_LEADERBOARD_H
#define ARCADE_LEADERBOARD_H

#include <string>

#include "score_entry.h"

/// @file leaderboard.h
/// @brief The Arcade's High Scores.

/// The most scores a leaderboard keeps.
inline constexpr int max_scores = 100;

/// A list of finished games that can be sorted and searched.
///
/// The sorting and searching is done by the functions in sorting.h; this
/// class only chooses which one to call and keeps track of the order.
class Leaderboard {
public:
  Leaderboard();

  /// Record a finished game.
  /// @return false if the leaderboard is full
  bool add(const std::string &name, int score, const std::string &game);

  /// @return the number of entries
  int count() const;

  /// @param index 0 to count() - 1
  /// @return the entry at @p index
  const ScoreEntry &at(int index) const;

  /// Sort by score, highest first, with insertion_sort.
  /// @param comparisons increased by the work done
  void sort_by_score(long &comparisons);

  /// Sort by name with selection_sort.
  /// @param comparisons increased by the work done
  void sort_by_name(long &comparisons);

  /// @return true if the entries are currently in name order
  bool sorted_by_name() const;

  /// Linear search, in whatever order the entries are in.
  /// @return the index of the first entry with this name, or -1
  int find_name_linear(const std::string &name, long &comparisons) const;

  /// Binary search. Call sort_by_name() first.
  /// @return the index of an entry with this name, or -1
  int find_name_binary(const std::string &name, long &comparisons) const;

  /// The High Scores menu. Returns when the player chooses 0.
  void run_menu();

private:
  /// How the entries are ordered right now.
  enum class Order { added, by_score, by_name };

  ScoreEntry m_entries[max_scores];
  int m_count;
  Order m_order;
};

#endif // ARCADE_LEADERBOARD_H
