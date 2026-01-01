#pragma once
#include "entity.hpp"

class Enemy : public Entity {
    int health;
    int attackDamage;

public:
    Enemy() : health(100), attackDamage(1) { pos = {0,0}; };
    void restoreHealth(int heal);    
    void takeDamage(int damage);
    void onPlayerCollision() override;
};
