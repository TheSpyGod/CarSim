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
#include "../fight/fight.h"

class Map {
private:
    const int width, height;
    std::vector<Entity> entities;
    std::vector<std::vector<Entity*>> grid;

    Fight& fight;

    inline int idx(int x, int y) const { return x * width + y; }

public:
    
    Map(int w, int h, Fight& fightRef);

    const std::vector<Entity*> getEntitiesAt(int x, int y) const;

    const std::vector<Entity*> getPlayerCell() const;

    bool isInsideGrid(Entity& e) const;

    void setEntity(Entity& e);

    const std::vector<std::vector<Entity*>>& getGrid() const;

    const int getWidth() const;
 
    void computeGrid();

    void randomize();

    bool isPlayerAlive();

    void checkCollision();

    void moveObject(int dx, int dy, Entity& obj);

    void movePlayer(int key);

};
