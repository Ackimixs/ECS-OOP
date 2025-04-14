#pragma once

#include <Health.hpp>
#include <Position.hpp>

#include "Character.hpp"
#include "Entity.hpp"

class Enemy : public Character
{
public:
    Enemy(int health, float x, float y, float z) : Character(health, x, y, z)
    {
        name_ = "Enemy_";
    }
};
