
#pragma once
#include "../core/EntityManager.hpp"
#include "../components/Position.hpp"
#include "../components/Velocity.hpp"
#include "SystemManager.hpp"
#include <iostream>

class MovementSystem : public ISystem {
public:
    MovementSystem(EntityManager& em) : entityManager(em) {}

    void Update(double dt) override {
        for (auto& [id, entity] : entityManager.entities_) {
            auto pos = entity->GetComponent<PositionComponent>();
            auto vel = entity->GetComponent<VelocityComponent>();
            if (pos && vel) {
                pos->x_ += vel->dx_ * dt;  // simulate 60fps movement
                pos->y_ += vel->dy_ * dt;
                pos->z_ += vel->dz_ * dt;
            }
        }
    }

private:
    EntityManager& entityManager;
};
