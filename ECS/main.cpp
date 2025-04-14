
#include <chrono>
#include <thread>

#include "Enemy.hpp"
#include "Projectile.hpp"
#include "entities/Player.hpp"
#include "core/EntityManager.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/HealthSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/SystemManager.hpp"

#define FPS 120.0f

int main() {
    EntityManager em;
    auto player = em.CreateEntity<Player>(100, 10, 3);
    auto enemy = em.CreateEntity<Enemy>(100, 3, 4);
    em.CreateEntity<Projectile>(3, 4);

    SystemManager systems;
    systems.RegisterSystem(std::make_shared<MovementSystem>(em));
    systems.RegisterSystem(std::make_shared<RenderSystem>(em));
    auto healthSys = std::make_shared<HealthSystem>(em);
    systems.RegisterSystem(healthSys);

    double timeBetweenFrames = 0;
    for (int i = 0; i < 200; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        std::cout << "\n[ECS] Frame " << i+1 << " - tick : " << timeBetweenFrames << "\n";
        systems.UpdateAll(timeBetweenFrames);

        if (i == 2) {
            healthSys->DamageEntity(player, 30);
        }
        if (i == 4) {
            healthSys->DamageEntity(enemy, 60);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> frameTime = end - start;

        double frameDuration = frameTime.count(); // en secondes
        double sleepDuration = (1/FPS) - frameDuration;

        if (sleepDuration > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepDuration));
            timeBetweenFrames = 1/FPS;
        }
        else
        {
            timeBetweenFrames = frameDuration;
        }
    }

    return 0;
}
