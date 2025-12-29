#include "headers/enemy.hpp"

void Enemy::restoreHealth(int heal) {
    health += heal;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
}

void Enemy::onPlayerCollision() {
    //Print Enemy scene, seperate fighting logic
}
