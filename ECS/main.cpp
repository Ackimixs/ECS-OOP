
#include <chrono>
#include <fstream>
#include <thread>

#include "Enemy.hpp"
#include "Projectile.hpp"
#include "Player.hpp"
#include "EntityManager.hpp"
#include "MovementSystem.hpp"
#include "HealthSystem.hpp"
#include "RenderSystem.hpp"
#include "SystemManager.hpp"
#include "GravitySystem.hpp"

int main() {


    auto FPS = 60.0f;

    auto prog_start = std::chrono::high_resolution_clock::now();

    std::ofstream file("log.csv");
    file << "frame,z,dz\n";

    EntityManager em;
    auto player = std::make_shared<Player>(100.0, 10.0, 3.0, 5.0);
    auto vc = player->GetComponent<VelocityComponent>();
    auto playerId = em.AddEntity(player);
    auto enemyId = em.AddEntity(std::make_shared<Enemy>(100.0, 3.0, 4.0, 12.0));
    em.AddEntity(std::make_shared<Projectile>(3.0, 4.0, 5.0));

    SystemManager systems;
    systems.RegisterSystem(std::make_shared<GravitySystem>(em));
    systems.RegisterSystem(std::make_shared<MovementSystem>(em));
    //systems.RegisterSystem(std::make_shared<RenderSystem>(em));
    auto healthSys = std::make_shared<HealthSystem>(em);
    systems.RegisterSystem(healthSys);

    double timeBetweenFrames = 1/FPS;
    for (int i = 0; i < FPS*10; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        std::cout << "\n[ECS] Frame " << i+1 << " - FPS : " << 1/timeBetweenFrames << "\n";
        systems.UpdateAll(timeBetweenFrames);

        if (i % 20 == 0) {
            healthSys->DamageEntity(playerId, 30);
        }
        if (i % 10 == 0) {
            healthSys->DamageEntity(enemyId, 60);
        }

        if (i == 12)
        {
            vc->dz_ = 40;
        }

        file << i << "," << player->GetComponent<PositionComponent>()->z_ << "," << vc->dz_ << "\n";

        auto sleepUntil = start + std::chrono::duration<double>(1.0 / FPS);

        std::this_thread::sleep_until(sleepUntil);

        timeBetweenFrames = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
    }

    file.close();

    auto prog_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> prog_duration = prog_end - prog_start;
    std::cout << "\n[ECS] Program duration: " << prog_duration.count() << " seconds\n";

    return 0;
}
