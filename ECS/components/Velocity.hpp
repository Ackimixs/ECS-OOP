#pragma once

#include <vector>

#include "Components.hpp"

class VelocityComponent : public IComponent
{
public:
    VelocityComponent() = default;

    VelocityComponent(float dx = 0, float dy = 0, float dz = 0) : dx_(dx), dy_(dy), dz_(dz)
    {
    }

    void Tick(float dt) override
    {
    }

    float dx_, dy_, dz_;
};
