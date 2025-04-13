
#pragma once
#include <vector>
#include <memory>

class ISystem {
public:
    virtual void Update(double dt) = 0;
    virtual ~ISystem() = default;
};

class SystemManager {
public:
    void RegisterSystem(std::shared_ptr<ISystem> system) {
        systems_.push_back(system);
    }

    void UpdateAll(double dt) {
        for (auto& sys : systems_) {
            sys->Update(dt);
        }
    }

private:
    std::vector<std::shared_ptr<ISystem>> systems_;
};
