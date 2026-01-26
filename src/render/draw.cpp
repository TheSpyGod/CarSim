#include "draw.hpp"
void Draw::drawMap(const std::vector<std::vector<Entity*>> &grid, int width) {
    int y = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); j++) {

        int x = (i % width) * w;   
        y = (i / width) * h;        

        Entity* cell = grid[i][j];
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
}

void Draw::DrawBackground(EntityType type, Texture2D& background) {
    
    switch (type) {
        case EntityType::Enemy: background = LoadTexture("../img/enemy.png"); break;
        case EntityType::Item: background = LoadTexture("../img/item.png"); break;
        case EntityType::Empty: background = LoadTexture("../img/empty.png"); break;
    }

    //Go through entities and check if both have the same x and y values 
}
