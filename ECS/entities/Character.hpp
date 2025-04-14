#pragma once
#include <Entity.hpp>
#include <Health.hpp>

class Character : public Entity
{
public:
    Character(int health)
    {
        name_ = "Character_";
        AddComponent(std::make_shared<Health>(Health(health)));
    }
};
