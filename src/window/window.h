#pragma once
#include "../render/draw.hpp"
#include <raylib.h>
#include "../grid/map.hpp"

class Window {
public:
    Texture2D background;
    void init();
};
