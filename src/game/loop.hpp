#pragma once

#include "../window/window.h"
#include "../grid/map.hpp"

class Loop {
private:
    Map m;
    Window win;

public:
    Loop();

    void init();

    void startLoop();

};


