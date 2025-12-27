#pragma once
#include <utility>

class Entity {
private:
    std::pair<int, int> pos;
    
public:
    void set(int x, int y);

    std::pair<int, int> get();

};
