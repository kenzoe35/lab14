#ifndef ARCADE_SCORE_ENTRY_H
#define ARCADE_SCORE_ENTRY_H

#include <string>

/// @file score_entry.h
/// @brief One line of the leaderboard.

/// A finished game: who played, what they scored, and which game it was.
struct ScoreEntry {
  std::string name;
  int score;
  std::string game;
};

#endif // ARCADE_SCORE_ENTRY_H
