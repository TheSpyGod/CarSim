#pragma once

#include "entity.hpp"
#include <vector>
#include <utility>

class Cursor;

class Map {
private:
    const int width, height;
    std::vector<std::vector<Entity*>> mapGrid(width * height, std::vector<Entity*>(width * height, nullptr));

public:
    Map(int w, int h);
    
    char getItem(int x, int y) const;

    std::vector<std::vector<Entity*>> getMap() const;

    std::pair<int, int> getItemPos(Entity target) const;

    int getSize() const;

    bool checkIfExists(Entity target) const;

    //TODO Fix logic for movement, when hitting a corner it doesnt stop
    bool checkIfCanMove(int x, int y) const;

    void move(int x, int y, Entity target);

    bool checkScene(int x, int y) const;

    void movePlayer(int direction);

};
