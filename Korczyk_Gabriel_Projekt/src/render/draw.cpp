#include "draw.hpp"
void Draw::drawMap(const std::vector<Entity*> &grid, int width) {
    int y = 0;

    for (int i = 0; i < grid.size(); ++i) {
        int x = (i % width) * w;   
        y = (i / width) * h;        

        Entity* cell = grid[i];
        if (!cell) {
            DrawRectangle(x, y, w, h, WHITE);
            continue;
        }

        switch (cell->type) {
            case EntityType::Enemy:  DrawRectangle(x, y, w, h, RED); break;
            case EntityType::Empty:  DrawRectangle(x, y, w, h, WHITE); break;
            case EntityType::Item:   DrawRectangle(x, y, w, h, YELLOW); break;
            case EntityType::Player: DrawRectangle(x, y, w, h, BLUE); break;
        }
    }
}

