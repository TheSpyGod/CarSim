//TODO
// - Fix player movement 
// - Implemnet proper Entities
#include "./map.hpp"
#include "../entities/entity.hpp"

Map::Map(int w, int h) : width(w), height(h), map(h, std::vector<Entity>(w)) {};

Entity& Map::get(int x, int y) { return map[x][y]; }

void Map::set(int x, int y, Entity e) { map[x][y] = e; }

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
        std::swap(targetCell, player);
        player.x = nx;
        player.y = ny;
    }
}

void Map::movePlayer(char direction) {
  //TODO Add in the Cursor implementation and movement   
    switch (direction) {
        case 'w':
            moveObject(0, -1);
        break;

        case 's':
            moveObject(0, 1);
        break;

        case 'a':
            moveObject(-1, 0);
        break;

        case 'd':
            moveObject(1, 0);
        break;
    }
}
