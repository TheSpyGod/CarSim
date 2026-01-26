#include "window.h"

void Window::init() {

    InitWindow(800,800,"TEST");
 
    Map m(20,20);
    Draw d;
    m.randomize();

    d.DrawBackground(m.findPlayer()->type, background);
    
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
