#pragma once

#include "Components.hpp"

class Position : public IComponent
{
public:
    Position() = default;

    Position(float x, float y) : x(x), y(y)
    {
    }

    float x = 0, y = 0;

    void Tick(float dt) override
    {
    }
};
