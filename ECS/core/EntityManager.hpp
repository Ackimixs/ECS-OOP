
#pragma once
#include "../entities/Entity.hpp"
#include <unordered_map>
#include <memory>

class EntityManager {
public:
    using ID = int;

    template<typename T, typename... Args>
    ID CreateEntity(Args&&... args) {
        static_assert(std::is_base_of<Entity, T>::value, "T must inherit from Entity");
        ID id = next++;
        auto entity = std::make_shared<T>(std::forward<Args>(args)...);
        entity->SetId(id);
        entities_[id] = entity;
        return id;
    }

    std::shared_ptr<Entity> GetEntity(ID id) {
        return entities_[id];
    }

    std::unordered_map<ID, std::shared_ptr<Entity>> entities_;

private:
    ID next = 0;
};