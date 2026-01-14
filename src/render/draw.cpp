#include "draw.hpp"
void Draw::drawMap(const std::vector<std::vector<Entity>> &map) {
    int y = 0;
    for (const std::vector<Entity> &row : map) {
        int x = 0;
        for (const Entity &cell : row) {
            if (cell.type == EntityType::Enemy) DrawRectangle(x,y,w,h,RED);
            if (cell.type == EntityType::Empty) DrawRectangle(x,y,w,h,WHITE);
            if (cell.type == EntityType::Item) DrawRectangle(x,y,w,h,YELLOW);
            if (cell.type == EntityType::Player) DrawRectangle(x,y,w,h,BLUE);
            x+=20;
        }
        y+=20;
    }
}
