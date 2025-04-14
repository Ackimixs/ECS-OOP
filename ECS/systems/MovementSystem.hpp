
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
            auto pos = entity->GetComponent<Position>();
            auto vel = entity->GetComponent<Velocity>();
            if (pos && vel) {
                pos->x += vel->dx * dt * 60;  // simulate 60fps movement
                pos->y += vel->dy * dt * 60;
            }
        }
    }

private:
    EntityManager& entityManager;
};
