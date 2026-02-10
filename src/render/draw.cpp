#include "draw.hpp"
void Draw::drawMap(const std::vector<std::vector<Entity*>> &grid, int width) {

    for (int i = 0; i < grid.size(); ++i) {
        const auto& cell = grid[i];
        int x = (i % width) * w;   
        int y = (i / width) * h;

    if (cell.empty()) {
        //DrawRectangle(x, y, w, h, WHITE);
        continue;
    }

    Entity* top = cell.back();
    switch (top->type) {
        case EntityType::Enemy:  DrawRectangle(x, y, w, h, RED); break;
        case EntityType::Item:   DrawRectangle(x, y, w, h, YELLOW); break;
        case EntityType::Player: DrawRectangle(x, y, w, h, BLUE); break;
        case EntityType::Empty:  DrawRectangle(x, y, w, h, WHITE); break;
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
