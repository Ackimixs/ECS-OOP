#pragma once

#include "Components.hpp"

class HealthComponent : public IComponent
{
public:
    HealthComponent() = default;

    explicit HealthComponent(int hp) : hp(hp)
    {
    }

    int hp = 0; // -1 means no HP

    void Tick(float dt) override
    {
    }
};
