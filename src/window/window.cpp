#include "window.h"
void Window::init() {
    InitWindow(800,800,"TEST");
 
    Map m(20,20);
    Draw d;
    m.randomize();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        d.drawMap(m.get());
        m.movePlayer(GetKeyPressed());
        EndDrawing();
    }

    CloseWindow();
}
