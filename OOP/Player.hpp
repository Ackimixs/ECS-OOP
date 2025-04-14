
#pragma once
#include <iostream>
#include <string>

class Player {
public:
    Player(std::string name, float x, float y, float dx, float dy, int hp)
        : name_(std::move(name)), x_(x), y_(y), dx_(dx), dy_(dy), hp_(hp) {}

    void Update(double dt) {
        x_ += dx_ * dt * 60;
        y_ += dy_ * dt * 60;
    }

    void Render() const {
        std::cout << "[Render] " << name_ << " Pos(" << x_ << ", " << y_ << ")";
        if (hp_ >= 0)
            std::cout << " HP=" << hp_;
        std::cout << "\n";
    }

    void TakeDamage(int amount) {
        if (hp_ < 0) return; // no HP
        hp_ -= amount;
        std::cout << "[HealthSystem] " << name_ << " took " << amount << " damage. HP = " << hp_ << "\n";
        if (hp_ <= 0) {
            std::cout << "[HealthSystem] " << name_ << " has died!\n";
        }
    }

private:
    std::string name_;
    float x_, y_;
    float dx_, dy_;
    int hp_;
};
