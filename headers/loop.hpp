#pragma once

#include "interface.hpp"
#include "map.hpp"

class Loop {
private:
    Map m;
    Interface f;

public:
    Loop();

    void init();

    void startLoop();

};


