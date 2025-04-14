#pragma once

#include <Velocity.hpp>
#include <Gravity.hpp>
#include <EntityManager.hpp>
#include <SystemManager.hpp>

class GravitySystem : public ISystem
{
public:
    GravitySystem(EntityManager& em) : entityManager_(em) {}

    void Update(double dt) override
    {
        for (auto& [id, entity] : entityManager_.entities_)
        {
            auto pos = entity->GetComponent<PositionComponent>();
            auto vel = entity->GetComponent<VelocityComponent>();
            auto gravity = entity->GetComponent<GravityComponent>();
            if (gravity && vel && pos)
            {
                auto gravityScale = gravity->GetGravity();
                std::vector directions = gravity->GetGravityDirections();
                vel->dx_ += static_cast<float>(dt) * (gravityScale * directions[0]);
                vel->dy_ += static_cast<float>(dt) * (gravityScale * directions[1]);

                if (pos->z_ >= 0)
                {
                    vel->dz_ += static_cast<float>(dt) * (gravityScale * directions[2]);
                }
                else
                {
                    vel->dz_ = 0;
                    pos->z_ = 0;
                }
            }
        }
    }

protected:
    EntityManager entityManager_;
};
