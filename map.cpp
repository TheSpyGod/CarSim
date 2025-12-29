//TODO
// - Fix player movement 
// - Implemnet proper Entities

#include "headers/map.hpp"
Map::Map(int w, int h) : width(w), height(h) {}

Entity* Map::getItem(int x, int y) const {
    return mapGrid[x][y];
}

std::vector<std::vector<Entity*>> Map::getMap() const {
    return mapGrid;
}

std::pair<int, int> Map::getItemPos(Entity target) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            if (mapGrid[i][j] == target) return std::make_pair(x,y);
        }
    }
    return {0,0};
}

void Map::set(int x, int y, Entity target) {
}

bool Map::checkIfExists(Entity target) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (mapGrid[i][j] == target) return true;
        }
    }
    return false;
}

bool Map::checkIfCanMove(int x, int y) const {
    return (x >= 0 && x < height) && (y >= 0 && y < width);
}

void Map::move(int x, int y, Entity target) {
//TODO icon is redundant, make it differenciate between player, enemy, obstacle and item
    if (checkIfCanMove(x,y)) mapGrid[x][y] = target;
}

void Map::checkScene(int x, int y) {
    int c = tiles[x * y];
    if (c == '0') return;

    if (c == '&') // Enemy
    else if (c == '$') //Item
}

void Map::movePlayer(int direction) {
    
    //TODO Add in the Cursor implementation and movement   
    switch (direction) {
        case 'w':
            move(x-1, y, 'p');
            move(x, y,'0');
            checkScene(x-1,y);
        break;

        case 's':
            move(x+1, y, 'p');
            move(x, y,'0');
            checkScene(x+1,y);
        break;

        case 'a':
            move(x, y-1, 'p');
            move(x, y,'0');
            checkScene(x,y-1);
        break;

        case 'd':
            move(x, y+1, 'p');
            move(x, y,'0');
            checkScene(x,y+1);
        break;
    }
}
