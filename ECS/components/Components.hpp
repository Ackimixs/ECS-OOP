#pragma once

class IComponent
{
public:
    virtual ~IComponent() = default;
    virtual void Tick(float dt) = 0;
};
