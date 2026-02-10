#include "window.h"

void Window::loadTextures() {
    textures[(int)EntityType::Enemy] = LoadTexture("../img/enemy.png");
    textures[(int)EntityType::Item] = LoadTexture("../img/item.png");
    textures[(int)EntityType::Empty] = LoadTexture("../img/empty.png");
}

void Window::unloadTextures() {
    for (int i = 0; i < (int)EntityType::COUNT; i++)
    UnloadTexture(textures[i]);
}

void Window::init() {

    InitWindow(800,800,"TEST");
     
    loadTextures();

    Map m(20,20,fight);
    Draw d;
    m.randomize();
    m.computeGrid();

    while (!WindowShouldClose()) {
        BeginDrawing();
 
        int key = GetKeyPressed();
        if (key != 0) {
            m.movePlayer(key);
            m.computeGrid();
            m.checkCollision();
        }

        float dt = GetFrameTime();
        fight.updateFight(dt);

        DrawTexture(textures[(int)d.DrawBackground(m.getPlayerCell())], 0, 0, WHITE);
        d.drawMap(m.getGrid(), m.getWidth());

        EndDrawing();

        if (!m.isPlayerAlive()) break;
    }

    unloadTextures();
    CloseWindow();
}
