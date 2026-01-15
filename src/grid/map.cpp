//TODO
// - Fix player movement 
// - Implemnet proper Entities
#include "./map.hpp"
#include "../entities/entity.hpp"
#include <cstdlib>
#include <ctime>
#include <raylib.h>

Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<Entity>(w)), entities(rand() % 10 + 1) {};

//Map::Map() {}
//TODO 
// Seperate entities into TWO distinct vectors:
// Normal vector with ALL existing Entities
// Second Vector with the grid and some spaces pointing to the existing objects
//
Entity& Map::get(int x, int y) { return map[x * width + y]; }

std::vector<std::vector<Entity>> Map::get() { return map; }

void Map::set(int x, int y, Entity* e) { map[x * width + y] = e; }

void Map::randomize() {
    
    int r = 0;
    for (int i = 0; i < entities.size(); i++) {
        if (entities[0].type != EntityType::Player) entities[0].type = EntityType::Player;
        
        Entity e = entities[i];

        r = rand() % 3;
        if (r == 1) e.type = EntityType::Enemy;
        else e.type = EntityType::Item;
    }

    for (int i = 0; i < entities.size(); i++) {
        grid[i] = *entities[i];
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    std::shuffle(grid.begin(), grid.end(), rng);
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
    if (targetCell.type == EntityType::Empty) std::swap(targetCell.type, player.type); 
    else if (targetCell.type == EntityType::Enemy) {
        targetCell.type = EntityType::Player;
        player.type = EntityType::Empty;
        

        //Raise flag for enemy battle, to check which enemy, search for if player.coords == enemy.coords
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
