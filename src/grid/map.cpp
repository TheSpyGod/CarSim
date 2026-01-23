//TODO
// - Fix player movement 
// - Implemnet proper Entities
#include "./map.hpp"

Map::Map(int w, int h) : width(w), height(h), grid(width * height) {
    srand(time(0));

    entities.resize(rand() % 10 + 1);
};

//Map::Map() {}
//TODO 
//
//Remake the map and how tiles work
//So far tiles were single entity, but what if i want multiple entities on a single tile?
//
//
//
std::vector<Entity*> Map::get(int x, int y) { return grid[idx(x, y)]; }

const std::vector<std::vector<Entity*>>& Map::getGrid() const { return grid; }

const int Map::getWidth() const { return width; }

void Map::set(int x, int y, Entity* e) { grid[idx(x, y)].insert(grid[idx(x, y)].begin(), e) }

void Map::randomize() {
    if (entities.empty()) return;

    entities[0].type = EntityType::Player;

    for (size_t i = 1; i < entities.size(); ++i) {
        entities[i].type = (rand() % 2 == 0) ? EntityType::Enemy : EntityType::Item;
    }

    std::fill(grid.begin(), grid.end(), nullptr);

    for (size_t i = 0; i < entities.size(); ++i) {
        int r = rand() % grid.size() - 1;
        grid[r].insert(grid[r].begin(), &entities[i]);
    }

    std::shuffle(grid.begin(), grid.end(), std::mt19937{ std::random_device{}() });

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::vector<Entity*> e = get(i, j);
            
            for (int k = 0; k < e.size(); k++) {
                if (e[k]) {
                    e->x = i;
                    e->y = j;
                }
            }
    
        }
    }
}

bool Map::isInside(int x, int y) const {
    return (x >= 0 && x < height) && (y >= 0 && y < width);
}

Entity* Map::findPlayer() {
for (std::vector<Entity*> e : grid) {
    for (int k = 0; k < e.size(); k++) if (e && e->type == EntityType::Player) return e;
}
return nullptr;
}

//This only swaps the container NOT the player within them :(
void Map::moveObject(int dx, int dy) {
    Entity* player = findPlayer();
    if (!player) return;

    int nx = player->x + dx;
    int ny = player->y + dy;

    if (!isInside(nx, ny)) return;

    Entity* target = get(nx, ny);

    if (!target || target->type == EntityType::Empty) {
        std::swap(grid[idx(player->x, player->y)], grid[idx(nx, ny)]);
        player->x = nx;
        player->y = ny;
    }
    else if (target->type == EntityType::Enemy) {
        std::swap(grid[idx(player->x, player->y)], grid[idx(nx, ny)]);
        grid[idx(nx, ny)] = player;
        player->x = nx;
        player->y = ny;
        // Instead of switching
        // Trigger fight scene and override enemy when won
    }
    else if (target->type == EntityType::Item) {
        std::swap(grid[idx(player->x, player->y)], grid[idx(nx, ny)]);
        player->x = nx;
        player->y = ny;
        //Increase player damage
    }
}

void Map::movePlayer(int key) {
  //TODO Add in the Cursor implementation and movement   
    switch (key) {
        case KEY_LEFT: moveObject(0, -1); break;
        case KEY_RIGHT: moveObject(0, 1); break;
        case KEY_UP: moveObject(-1, 0); break;
        case KEY_DOWN: moveObject(1, 0); break;
    }
}
