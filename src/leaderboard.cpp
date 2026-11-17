#include "leaderboard.h"

#include <iomanip>
#include <iostream>

#include "input.h"
#include "sorting.h"

namespace {

void print_entry(int position, const ScoreEntry &entry) {
  std::cout << std::setw(3) << position << ". " << std::left << std::setw(14)
            << entry.name << std::right << std::setw(6) << entry.score << "  "
            << entry.game << "\n";
}

void print_found(const Leaderboard &board, int index, long comparisons) {
  if (index < 0) {
    std::cout << "Not found.\n";
  } else {
    std::cout << "Found:\n";
    print_entry(index + 1, board.at(index));
  }
  std::cout << "Comparisons: " << comparisons << "\n";
}

} // namespace

Leaderboard::Leaderboard() : m_entries{}, m_count{0}, m_order{Order::added} {}

bool Leaderboard::add(const std::string &name, int score,
                      const std::string &game) {
  if (m_count == max_scores) {
    return false;
  }
  m_entries[m_count] = ScoreEntry{name, score, game};
  ++m_count;
  m_order = Order::added;
  return true;
}

int Leaderboard::count() const { return m_count; }

const ScoreEntry &Leaderboard::at(int index) const { return m_entries[index]; }

void Leaderboard::sort_by_score(long &comparisons) {
  insertion_sort(m_entries, m_count, score_descending, comparisons);
  m_order = Order::by_score;
}

void Leaderboard::sort_by_name(long &comparisons) {
  selection_sort(m_entries, m_count, name_ascending, comparisons);
  m_order = Order::by_name;
}

bool Leaderboard::sorted_by_name() const { return m_order == Order::by_name; }

int Leaderboard::find_name_linear(const std::string &name,
                                  long &comparisons) const {
  return linear_search_name(m_entries, m_count, name, comparisons);
}

int Leaderboard::find_name_binary(const std::string &name,
                                  long &comparisons) const {
  return binary_search_name(m_entries, m_count, name, comparisons);
}

void Leaderboard::run_menu() {
  std::string line;
  while (true) {
    std::cout << "\n--- High Scores (" << m_count << " recorded) ---\n"
              << "1. Top 10 by score\n"
              << "2. All, sorted by name\n"
              << "3. Find a name (linear search)\n"
              << "4. Find a name (binary search; sort by name first)\n"
              << "0. Back\n";
    if (!prompt_line("Choose: ", line) || line == "0") {
      return;
    }
    long comparisons = 0;
    if (line == "1") {
      sort_by_score(comparisons);
      const int shown = m_count < 10 ? m_count : 10;
      for (int i = 0; i < shown; ++i) {
        print_entry(i + 1, m_entries[i]);
      }
      if (m_count == 0) {
        std::cout << "No scores yet.\n";
      }
      std::cout << "Comparisons: " << comparisons << "\n";
    } else if (line == "2") {
      sort_by_name(comparisons);
      for (int i = 0; i < m_count; ++i) {
        print_entry(i + 1, m_entries[i]);
      }
      if (m_count == 0) {
        std::cout << "No scores yet.\n";
      }
      std::cout << "Comparisons: " << comparisons << "\n";
    } else if (line == "3" || line == "4") {
      if (line == "4" && !sorted_by_name()) {
        std::cout << "Sort by name first (option 2).\n";
        continue;
      }
      std::string name;
      if (!prompt_line("Name: ", name)) {
        return;
      }
      const int index = line == "3" ? find_name_linear(name, comparisons)
                                    : find_name_binary(name, comparisons);
      print_found(*this, index, comparisons);
    } else {
      std::cout << "Please enter 0-4.\n";
    }
  }
}
