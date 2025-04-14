#include "Player.hpp"
#include "SystemManager.hpp"
#include <memory>
#include <vector>
#include <chrono>
#include <thread>

#define FPS 240.0f

int main() {
    SystemManager manager;

    auto player = std::make_shared<Player>("Player", 0, 0, 1.0f, 0.5f, 100);
    auto enemy = std::make_shared<Player>("Enemy", 5.0f, 2.0f, 0.0f, 0.0f, 80);
    auto projectile = std::make_shared<Player>("Projectile", 3.0f, 1.0f, 0.0f, 0.0f, -1);  // -1 means no HP

    manager.AddEntity(player);
    manager.AddEntity(enemy);
    manager.AddEntity(projectile);

    double timeBetweenFrames = 0;

    for (int i = 0; i < 200; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        std::cout << "\n[OOP] Frame " << i + 1 << " - tick: " << 1/timeBetweenFrames << "\n";
        manager.Update(timeBetweenFrames);

        if (i == 2) enemy->TakeDamage(30);
        if (i == 4) enemy->TakeDamage(60);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> frameTime = end - start;

        double frameDuration = frameTime.count();
        double sleepDuration = (1.0 / FPS) - frameDuration;

        if (sleepDuration > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepDuration));
            timeBetweenFrames = 1.0 / FPS;
        } else {
            timeBetweenFrames = frameDuration;
        }
    }

    return 0;
}
