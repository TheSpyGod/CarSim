#pragma once

#include "../entities/entity.hpp"
#include <vector>
#include <utility>
#include <random>
#include "../entities/entity.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <raylib.h>

class Map {
private:
    const int width, height;
    std::vector<Entity> entities;
    std::vector<std::vector<Entity*>> grid;

    inline int idx(int x, int y) const { return x * width + y; }

public:
    Map(int w, int h);

    Entity* get(int x, int y, int entityNumber);

    const std::vector<std::vector<Entity*>>& getGrid() const;

    const int getWidth() const;

    void set(int x, int y, Entity* target);
  
    void randomize();

    bool isInside(int x, int y) const;

    Entity* findPlayer();

    void moveObject(int dx, int dy);

    void movePlayer(int key);

};
