#pragma once

#include <vector>
#include <utility>

class Cursor;

class Map {
private:
    const int width, height;
    std::vector<char> tiles;

public:
    Map(int w, int h);
    
    char getItem(int x, int y) const;

    std::vector<char> getMap() const;

    int getWidth() const;

    std::pair<int, int> getItemPos(char target) const;

    void set(int x, int y, char value);

    int getSize() const;

    int checkIfExists(char icon) const;

    //TODO Fix logic for movement, when hitting a corner it doesnt stop
    bool checkIfCanMove(int x, int y) const;

    void move(int x, int y, char icon);

    bool checkScene(Cursor c) const;

    void movePlayer(int direction);

};
