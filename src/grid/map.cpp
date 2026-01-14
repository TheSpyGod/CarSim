//TODO
// - Fix player movement 
// - Implemnet proper Entities
#include "./map.hpp"
#include "../entities/entity.hpp"
#include <cstdlib>
#include <ctime>
#include <raylib.h>

Map::Map(int w, int h) : width(w), height(h), map(h, std::vector<Entity>(w)) {};

//Map::Map() {}

Entity& Map::get(int x, int y) { return map[x][y]; }

std::vector<std::vector<Entity>> Map::get() { return map; }

void Map::set(int x, int y, Entity e) { map[x][y] = e; }

void Map::randomize() {
    
    map[width/2][height/2].type = EntityType::Player;
    map[width/2][height/2].x = width / 2;
    map[width/2][height/2].y = height / 2;

    for (int i = 0; i < width; i++) {
        int n = 0;
        for (int j = 0; j < height; j++) {
            Entity &cell = map[i][j];
            if (cell.type == EntityType::Player) continue;
            n = rand() % 101;
            if (n <= 95) {
                cell.type = EntityType::Empty;
                cell.x = i;
                cell.y = j;
            }
            else if (n > 95 && n < 98) {
                cell.type = EntityType::Enemy;
                cell.x = i;
                cell.y = j;
            }
            else {
                cell.type = EntityType::Item;
                cell.x = i;
                cell.y = j;
            }
        }
    }
}

bool Map::isInside(int x, int y) const {
    return (x >= 0 && x < height) && (y >= 0 && y < width);
}

Entity& Map::findPlayer() {
    for (auto &row : map)
        for (auto &cell : row)
            if (cell.type == EntityType::Player) return cell;
}

void Map::moveObject(int dx, int dy) {
    Entity &player = findPlayer();
    int nx = player.x + dx;
    int ny = player.y + dy;

    if (!isInside(nx, ny)) return;
    
    Entity &targetCell = get(nx, ny);
    if (targetCell.type == EntityType::Empty) {
        std::swap(targetCell.type, player.type);
        //targetCell.x = nx;
        //targetCell.y = ny;
    }
}

void Map::movePlayer(int key) {
  //TODO Add in the Cursor implementation and movement   
    switch (key) {
        case KEY_LEFT:
            moveObject(0, -1);
        break;

        case KEY_RIGHT:
            moveObject(0, 1);
        break;

        case KEY_UP:
            moveObject(-1, 0);
        break;

        case KEY_DOWN:
            moveObject(1, 0);
        break;
    }
}
