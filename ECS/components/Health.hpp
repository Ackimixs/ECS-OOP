#pragma once

#include "Components.hpp"

class Health : public IComponent
{
public:
    Health() = default;

    explicit Health(int hp) : hp(hp)
    {
    }

    int hp = 0; // -1 means no HP

    void Tick(float dt) override
    {
    }
};
