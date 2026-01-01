#pragma once

#include "../window/interface.hpp"
#include "../grid/map.hpp"

class Loop {
private:
    Map m;
    Interface f;

public:
    Loop();

    void init();

    void startLoop();

};


