
#pragma once
#include "Entity.hpp"
#include <unordered_map>
#include <memory>

class EntityManager {
public:
    using ID = int;
    ID CreateEntity() {
        ID id = next++;
        entities_[id] = std::make_shared<Entity>();
        return id;
    }
    std::shared_ptr<Entity> GetEntity(ID id) { return entities_[id]; }

    std::unordered_map<ID, std::shared_ptr<Entity>> entities_;
private:
    ID next = 0;
};
