#include "headers/player.hpp"

void Player::restoreHealth(int heal) {
    health += heal;
}

void Player::takeDamage(int damage) {
    health -= damage;
}
