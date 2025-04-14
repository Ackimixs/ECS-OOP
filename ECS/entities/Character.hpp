#pragma once
#include <Entity.hpp>
#include <Health.hpp>

#include "Actor.hpp"

class Character : public Actor
{
public:
    Character(int health, float x, float y, float z) : Actor(x, y, z)
    {
        name_ = "Character_";
        AddComponent(std::make_shared<HealthComponent>(HealthComponent(health)));
    }
};
