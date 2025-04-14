#pragma once

#include "Components.hpp"

class Velocity : public IComponent
{
public:
    Velocity() = default;

    Velocity(float dx, float dy) : dx(dx), dy(dy)
    {
    }

    float dx = 0, dy = 0;

    void Tick(float dt) override
    {
    }
};
