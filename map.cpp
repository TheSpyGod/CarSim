#include "map.hpp"
#include "cursor.hpp"

Map::Map(int w, int h) : width(w), height(h), tiles(w * h) {}

char Map::getItem(int x, int y) const {
    return tiles[y * width + x];
}

std::vector<char> Map::getMap() const {
    return tiles;
}

int Map::getWidth() const {
    return width;
}

std::pair<int, int> Map::getItemPos(char target) const {
    for (int i = 0; i < tiles.size(); ++i) {
        if (tiles[i] == target) {
            int x = i % width;
            int y = i / width;
            return std::make_pair(x,y);
        }
    }
    return {0,0};
}

void Map::set(int x, int y, char value) {
    tiles[y * width + x] = value;
}

int Map::getSize() const {
    return height * width;
}

int Map::checkIfExists(char icon) const {
    for (char c : tiles) {
        if (c == icon)
            return true;
    }
    return false;
}

bool Map::checkIfCanMove(int x, int y) const {
    return (x >= 0 && x < height) &&
           (y >= 0 && y < width);
}

void Map::move(int x, int y, char icon) {
//TODO icon is redundant, make it differenciate between player, enemy, obstacle and item
    if (checkIfCanMove(x,y))
        set(x,y,icon);
}

bool Map::checkScene(Cursor c) const {
    if (tiles[c.getX() * c.getY()] != '0')
        return true;
    else
        return false;
}

void Map::movePlayer(int direction) {
    std::pair<int, int> playerPos = getItemPos('p');
    //TODO Add in the Cursor implementation and movement   
    switch (direction) {
        case 'w':
            move(playerPos.first-1, playerPos.second, 'p');
            move(playerPos.first, playerPos.second,'0');
        break;

        case 's':
            move(playerPos.first+1, playerPos.second, 'p');
            move(playerPos.first, playerPos.second,'0');
        break;

        case 'a':
            move(playerPos.first, playerPos.second-1, 'p');
            move(playerPos.first, playerPos.second,'0');
        break;

        case 'd':
            move(playerPos.first, playerPos.second+1, 'p');
            move(playerPos.first, playerPos.second,'0');
        break;
    }
}
