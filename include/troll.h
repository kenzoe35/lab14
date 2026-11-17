#ifndef ARCADE_TROLL_H
#define ARCADE_TROLL_H

#include "monster.h"

/// @file troll.h
/// @brief The Troll.

/// A Troll: 6 damage per hit.
class Troll : public Monster {
public:
  Troll();

  int attack_damage() const override;

  std::string describe() const override;
};

#endif // ARCADE_TROLL_H
