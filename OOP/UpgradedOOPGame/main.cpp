
#include "Player.hpp"
#include "SystemManager.hpp"
#include <memory>
#include <vector>

int main() {
    SystemManager manager;

    auto player = std::make_shared<Player>("Player", 0, 0, 1.0f, 0.5f, 100);
    auto enemy = std::make_shared<Player>("Enemy", 5.0f, 2.0f, 0.0f, 0.0f, 80);
    auto projectile = std::make_shared<Player>("Projectile", 3.0f, 1.0f, 0.0f, 0.0f, -1);  // -1 means no HP

    manager.AddEntity(player);
    manager.AddEntity(enemy);
    manager.AddEntity(projectile);

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n[OOP] Frame " << i + 1 << "\n";
        manager.Update(0.016);
        if (i == 2) enemy->TakeDamage(30);
        if (i == 4) enemy->TakeDamage(60);
    }

    return 0;
}
