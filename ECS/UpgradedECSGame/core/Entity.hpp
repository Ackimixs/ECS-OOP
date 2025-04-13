
#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>

class Entity {
public:
    template<typename T>
    void AddComponent(std::shared_ptr<T> comp) {
        components_[std::type_index(typeid(T))] = comp;
    }

    template<typename T>
    std::shared_ptr<T> GetComponent() {
        auto it = components_.find(std::type_index(typeid(T)));
        if (it != components_.end()) return std::static_pointer_cast<T>(it->second);
        return nullptr;
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> components_;
};
