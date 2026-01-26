#include "window.h"

Texture2D background;

void Window::init() {

    InitWindow(800,800,"TEST");
 
    background = LoadTexture("../img/empty.png");
    
    Map m(20,20);
    Draw d;
    m.randomize();

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);
        d.drawMap(m.getGrid(), m.getWidth());
        m.movePlayer(GetKeyPressed());
        EndDrawing();
    }
    
    UnloadTexture(background);
    CloseWindow();
}
