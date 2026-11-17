#ifndef ARCADE_GOBLIN_H
#define ARCADE_GOBLIN_H

#include "monster.h"

/// @file goblin.h
/// @brief The Goblin.

/// A Goblin: 3 damage per hit.
class Goblin : public Monster {
public:
  Goblin();

  int attack_damage() const override;
};

#endif // ARCADE_GOBLIN_H
