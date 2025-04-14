#pragma once

#include <Position.hpp>
#include <Velocity.hpp>

#include "Entity.hpp"

class Projectile : public Actor
{
public:
    Projectile(float x, float y, float z) : Actor(x, y, z)
    {
        name_ = "Projectile_";
    }
};
