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

        w = 10;
        h = 10;

        switch (cell->type) {
            case EntityType::Enemy:  DrawRectangle(x, y, w, h, RED); break;
            case EntityType::Empty:  DrawRectangle(x, y, w, h, WHITE); break;
            case EntityType::Item:   DrawRectangle(x, y, w, h, YELLOW); break;
            case EntityType::Player: DrawRectangle(x, y, w, h, BLUE); break;
        }
        }
    }
}

EntityType Draw::DrawBackground(std::vector<Entity*> container) {

    EntityType type = EntityType::Empty;

    for (auto entity : container) {
        if (entity != nullptr && entity->type != EntityType::Player) { 
            type = entity->type;
            break;
        }
    }    
  return type;
}
