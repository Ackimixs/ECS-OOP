
#include "core/EntityManager.hpp"
#include "core/Components.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/HealthSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/SystemManager.hpp"

int main() {
    EntityManager em;

    auto player = em.CreateEntity();
    em.GetEntity(player)->AddComponent(std::make_shared<Position>());
    em.GetEntity(player)->AddComponent(std::make_shared<Velocity>(Velocity{1.0f, 0.5f}));
    em.GetEntity(player)->AddComponent(std::make_shared<Health>(Health{100}));

    auto enemy = em.CreateEntity();
    em.GetEntity(enemy)->AddComponent(std::make_shared<Position>(Position{5.0f, 2.0f}));
    em.GetEntity(enemy)->AddComponent(std::make_shared<Health>(Health{80}));

    auto projectile = em.CreateEntity();
    em.GetEntity(projectile)->AddComponent(std::make_shared<Position>(Position{3.0f, 1.0f}));

    SystemManager systems;
    systems.RegisterSystem(std::make_shared<MovementSystem>(em));
    systems.RegisterSystem(std::make_shared<RenderSystem>(em));
    auto healthSys = std::make_shared<HealthSystem>(em);
    systems.RegisterSystem(healthSys);

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n[ECS] Frame " << i+1 << "\n";
        systems.UpdateAll(0.016);

        if (i == 2) {
            healthSys->DamageEntity(enemy, 30);
        }
        if (i == 4) {
            healthSys->DamageEntity(enemy, 60);
        }
    }

    return 0;
}
