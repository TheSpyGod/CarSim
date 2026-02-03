#pragma once
#include <utility>
enum class EntityType {Player, Enemy, Item, Empty, COUNT};

class Entity {
public:
    EntityType type;
    int x, y;
    int health;
    int initiative;
    int dmg;
    bool takeDamage(int damage) {
        if (health <= 0) return false;
        health -= damage;
        return true;
    }

    Entity() : type(EntityType::Empty), x(-1), y(-1), health(15), initiative(5), dmg(5){};
    virtual ~Entity();
};
