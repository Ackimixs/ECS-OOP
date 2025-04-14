#pragma once

#include <string>
#include <utility>

#include "Entity.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "../components/Health.hpp"

class Player : public Character {

public:
  Player(int health, float x, float y) : Character(health) {
    name_ = "Player_s";
    AddComponent(std::make_shared<Position>(Position(x, y)));
    AddComponent(std::make_shared<Velocity>(Velocity{1.0f, 0.5f}));
  };
};
