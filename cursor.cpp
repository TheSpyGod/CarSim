#include "headers/cursor.hpp"
#include <vector>

Cursor::Cursor(const int MAP_SIZE) : MAP_SIZE(this->MAP_SIZE) {}

int Cursor::getX() const {
    return x;
}

int Cursor::getY() const {
    return y;
}

int Cursor::getPos() const {
    return x * y;
}

void Cursor::set(int nx, int ny) {
    if ((nx > 0 && nx < MAP_SIZE - 1) && (ny > 0 && ny < MAP_SIZE - 1)) {
        x = nx;
        y = ny;
    }
}

void Cursor::offset(int ox, int oy) {
    set(x + ox, y + oy);
}
