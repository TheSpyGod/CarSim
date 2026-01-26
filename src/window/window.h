#pragma once
#include "../render/draw.hpp"
#include <raylib.h>
#include "../entities/entity.hpp"
#include "../grid/map.hpp"
#include <vector>

class Window {
public:
    Texture2D textures[(int)EntityType::COUNT];
    void loadTextures();
    void unloadTextures();
    void init();
};
