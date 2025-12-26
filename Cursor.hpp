#ifndef CURSOR_HPP
#define CURSOR_HPP

#include <vector>

class Cursor {
private:     
    int x = 6;
    int y = 7;
    char val;
    int MAP_SIZE;
public:

    Cursor(const int MAP_SIZE) {
        this->MAP_SIZE = MAP_SIZE;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getPos() {
        return x * y;
    }

    void set(int nx, int ny) {
        if ((nx > 0 && nx < MAP_SIZE - 1) && (ny > 0 && ny < MAP_SIZE - 1)) {
            x = nx;
            y = ny;
        }
    }

    void offset(int ox, int oy) {
        set(x + ox, y + oy);
    }
};

#endif 
