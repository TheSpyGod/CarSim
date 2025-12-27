#pragma once

#include "interface.hpp"
#include "cursor.hpp"
#include "map.hpp"

class Loop {
private:
    Map m;
    Interface f;
    Cursor c;

public:
    Loop();

    void init();

    void startLoop();

};


