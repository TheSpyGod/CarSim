#pragma once

class Cursor {
private:     
    int x = 6;
    int y = 7;
    char val;
    int MAP_SIZE;
public:

    Cursor(const int MAP_SIZE);

    int getX() const;

    int getY() const;

    int getPos() const;

    void set(int nx, int ny);

    void offset(int ox, int oy);

};

