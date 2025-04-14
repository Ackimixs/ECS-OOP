
#pragma once
#include "../core/EntityManager.hpp"
#include "../components/Health.hpp"
#include "SystemManager.hpp"
#include <iostream>

class HealthSystem : public ISystem {
public:
    HealthSystem(EntityManager& em) : entityManager(em) {}

    void Update(double) override {}

    void DamageEntity(int id, int amount) {
        auto entity = entityManager.GetEntity(id);
        auto hp = entity->GetComponent<Health>();
        if (hp) {
            hp->hp -= amount;
            std::cout << "[HealthSystem] " << entity->GetName() << " took " << amount << " damage. HP = " << hp->hp << "\n";
            if (hp->hp <= 0) {
                std::cout << "[HealthSystem] Entity " << id << " has died!\n";
            }
        }
    }

private:
    EntityManager& entityManager;
};
