#pragma once
#include <utility>
enum class EntityType {Player, Enemy, Item, Empty};

class Entity {
public:
    EntityType type;
    int x, y;
    Entity() : type(EntityType::Empty), x(-1), y(-1){};
    virtual ~Entity();
};
