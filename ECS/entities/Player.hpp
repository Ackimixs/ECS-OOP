#pragma once

#include <string>

#include "Entity.hpp"

class Player : public Character {

public:
  Player(int health, float x, float y, float z) : Character(health, x, y, z) {
    name_ = "Player_";
  }
};
