#pragma once
#include "../grid/map.hpp"
#include "../entities/entity.hpp"
#include <raylib.h>
#include <vector>

class Draw {
private:
    int w = 15;
    int h = 15;
public:
    void drawMap(const std::vector<std::vector<Entity*>> &grid, int width);
    EntityType DrawBackground(std::vector<Entity*> container);
};
