#pragma once

#include "Components.hpp"

class PositionComponent : public IComponent
{
public:
    PositionComponent() = default;

    PositionComponent(float x, float y, float z) : x_(x), y_(y), z_(z)
    {
    }

    float x_ = 0, y_ = 0, z_ = 0;

    void Tick(float dt) override
    {
    }
};
