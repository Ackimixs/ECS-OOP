
#pragma once
#include <iostream>
#include <string>

class Player {
public:
    Player(std::string name, float x, float y, float z, float dx, float dy, float dz, int hp)
        : name_(std::move(name)), x_(x), y_(y), z_(z), dx_(dx), dy_(dy), dz_(dz), hp_(hp) {}

    void Update(double dt) {
        x_ += dx_ * dt;
        y_ += dy_ * dt;
        dz_ += g * dt;
        z_ += dz_ * dt;
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

    void Jump() {
        dz_ = 5.0f; // initial jump velocity
    }

private:
    std::string name_;
    float x_, y_, z_;
    float dx_, dy_, dz_;
    float g = 9.81f;
    int hp_;
};
