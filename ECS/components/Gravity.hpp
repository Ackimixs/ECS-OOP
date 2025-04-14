#pragma once

#include <vector>

#include "Components.hpp"

class GravityComponent : public IComponent
{
public:
    void Tick(float dt) override
    {
    }

    GravityComponent(float g = 9.81, float x = 0, float y = 0, float z = 0) : IComponent(), gravity_(g), gravityDirections_({x, y, z}) {}

    [[nodiscard]] float GetGravity() const { return gravity_; }

    void SetGravity(float g) { gravity_ = g; }

    [[nodiscard]] std::vector<float> GetGravityDirections() const { return gravityDirections_; }

    void SetGravityDirections(float x, float y, float z) { gravityDirections_ = std::vector{x, y, z}; }
protected:
    float gravity_;

    std::vector<float> gravityDirections_;
};