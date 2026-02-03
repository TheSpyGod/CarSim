#pragma once
#include "../render/draw.hpp"
#include <raylib.h>
#include "../entities/entity.hpp"
#include "../grid/map.hpp"
#include "../fight/fight.h"
#include <vector>

class Window {
    Fight fight;
public:
    Texture2D textures[(int)EntityType::COUNT];
    void loadTextures();
    void unloadTextures();
    void init();
};
