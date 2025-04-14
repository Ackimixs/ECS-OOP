#pragma once

#include <Health.hpp>
#include <Position.hpp>

#include "Character.hpp"
#include "Entity.hpp"

class Enemy : public Character
{
public:
    Enemy(int health, float x, float y) : Character(health)
    {
        name_ = "Enemy_";
        AddComponent(std::make_shared<Position>(Position(x, y)));
    }
};
