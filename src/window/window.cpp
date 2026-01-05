#include "window.h"
#include <raylib.h>
void Window::init() {
    InitWindow(800,800,"TEST");
    
    while (!WindowShouldClose) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello!",200,200,20,LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}
