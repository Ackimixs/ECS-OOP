#pragma once

#include <Position.hpp>
#include <Velocity.hpp>

#include "Entity.hpp"

class Projectile : public Entity
{
public:
    Projectile(float x, float y)
    {
        name_ = "Projectile_";
        AddComponent(std::make_shared<Position>(Position(x, y)));
        AddComponent(std::make_shared<Velocity>(Velocity{1.0f, 0.5f}));
    }
};
