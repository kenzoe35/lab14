#include "troll.h"

Troll::Troll() : Monster{"Troll", 20} {}

int Troll::attack_damage() const { return 6; }

std::string Troll::describe() const {
  return "The hulking " + Monster::describe();
}
