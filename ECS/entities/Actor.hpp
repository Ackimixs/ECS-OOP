#pragma once

#include <Position.hpp>
#include <Velocity.hpp>

#include "Entity.hpp"
#include "Gravity.hpp"

class Actor : public Entity
{
public:
    Actor(float x, float y, float z)
    {
        AddComponent(std::make_shared<PositionComponent>(x, y, z));
        AddComponent(std::make_shared<VelocityComponent>(0.0f, 0.0f, 0.0f));
        AddComponent(std::make_shared<GravityComponent>(9.81, 0, 0, -1));
    }
};
