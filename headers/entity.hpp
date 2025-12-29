#pragma once
#include <utility>

class Entity {
    std::pair<int, int> pos;
    
public:
    void set(int x, int y);
    std::pair<int, int> get();
    virtual void onPlayerCollision();
    virtual ~Entity();
};
