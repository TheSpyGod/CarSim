#include "headers/entity.hpp"

void Entity::set(int x, int y) {
    pos.first = x;
    pos.second = y;
}

std::pair<int, int> Entity::get() {
    return pos;
}
