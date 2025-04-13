
#pragma once
#include "Player.hpp"
#include <vector>
#include <memory>

class SystemManager {
public:
    void AddEntity(std::shared_ptr<Player> p) {
        players_.push_back(p);
    }

    void Update(float dt) {
        for (auto& p : players_) {
            p->Update(dt);
        }
        for (auto& p : players_) {
            p->Render();
        }
    }

private:
    std::vector<std::shared_ptr<Player>> players_;
};
