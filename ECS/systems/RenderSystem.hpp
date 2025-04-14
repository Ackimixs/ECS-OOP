
#pragma once
#include "../core/EntityManager.hpp"
#include "../components/Health.hpp"
#include "../components/Position.hpp"
#include "SystemManager.hpp"
#include <iostream>

class RenderSystem : public ISystem {
public:
    RenderSystem(EntityManager& em) : entityManager(em) {}

    void Update(double) override {
        for (auto& [id, entity] : entityManager.entities_) {
            auto pos = entity->GetComponent<Position>();
            auto hp = entity->GetComponent<Health>();
            std::cout << "[Render] " << entity->GetName();
            if (pos) std::cout << " Pos(" << pos->x << ", " << pos->y << ")";
            if (hp) std::cout << " HP=" << hp->hp;
            std::cout << "\n";
        }
    }

private:
    EntityManager& entityManager;
};
