#include "arcade.h"

#include <iostream>
#include <string>

#include "input.h"

Arcade::Arcade() : m_games{}, m_count{0}, m_leaderboard{} {}

Arcade::~Arcade() {
  for (int i = 0; i < m_count; ++i) {
    delete m_games[i];
  }
}

void Arcade::add(Game *game) {
  if (m_count == max_games) {
    delete game;
    return;
  }
  m_games[m_count] = game;
  ++m_count;
}

void Arcade::run() {
  std::string line;
  while (true) {
    std::cout << "\n=== ARCADE ===\n";
    for (int i = 0; i < m_count; ++i) {
      std::cout << i + 1 << ". " << m_games[i]->title() << "\n";
    }
    std::cout << "H. High Scores\n0. Quit\n";
    if (!prompt_line("Choose: ", line)) {
      return;
    }
    if (line == "0") {
      return;
    }
    if (line == "h" || line == "H") {
      m_leaderboard.run_menu();
    } else if (line.size() == 1 && line[0] >= '1' && line[0] < '1' + m_count) {
      Game *game = m_games[line[0] - '1'];
      game->play();
      std::cout << game->title() << " score: " << game->last_score() << "\n";
      std::string name;
      if (prompt_line("Name for the leaderboard: ", name)) {
        if (name.empty()) {
          name = "Anon";
        }
        m_leaderboard.add(name, game->last_score(), game->title());
      }
    } else {
      std::cout << "Please enter 1-" << m_count << ", H, or 0 to quit.\n";
    }
  }
}
