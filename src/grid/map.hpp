#pragma once

#include "../entities/entity.hpp"
#include <vector>
#include <utility>

class Map {
private:
    const int width, height;
    std::vector<std::vector<Entity>> map;

public:
    Map(int w, int h);
 
    //Map();
    //Map();

    Entity& get(int x, int y);

    std::vector<std::vector<Entity>> get();

    void set(int x, int y, Entity target);
  
    void randomize();

    bool isInside(int x, int y) const;

    Entity& findPlayer();

    void moveObject(int dx, int dy);

    void movePlayer(int key);

};
