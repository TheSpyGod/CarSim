#pragma once
#include <utility>
enum class EntityType {Player, Enemy, Item, Empty};

class Entity {
public:
    EntityType type;
    int x, y;
    virtual ~Entity();
};
