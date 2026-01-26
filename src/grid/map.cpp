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

std::vector<Entity*> Map::get(int x, int y) { return grid[idx(x, y)]; }

const std::vector<std::vector<Entity*>>& Map::getGrid() const { return grid; }

const int Map::getWidth() const { return width; }

void Map::set(int x, int y, Entity* e) { grid[idx(x, y)].insert(grid[idx(x, y)].begin(), e); }

void Map::randomize() {
    if (entities.empty()) return;

    entities[0].type = EntityType::Player;

    for (size_t i = 1; i < entities.size(); ++i) {
        entities[i].type = (rand() % 2 == 0) ? EntityType::Enemy : EntityType::Item;
    }
  
    for (auto& row : grid) std::fill(row.begin(), row.end(), nullptr);

    for (size_t i = 0; i < entities.size(); ++i) {
        int r = rand() % grid.size() - 1;
        grid[r].insert(grid[r].begin(), &entities[i]);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::vector<Entity*>& e = grid[idx(i, j)];
            
            for (int k = 0; k < e.size(); k++) {
                if (e[k]) {
                    e[k]->x = i;
                    e[k]->y = j;
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
        for (int k = 0; k < e.size(); k++) if (e.size() > 0 && e[k]->type == EntityType::Player) return e[k];
    }
    return nullptr;
}

std::vector<Entity*> Map::findPlayerLocation() {
    for (std::vector<Entity*> e : grid) {
        for (int k = 0; k < e.size(); k++) if (e.size() > 0 && e[k]->type == EntityType::Player) return e;
    }
    return std::vector<Entity*> {};
}

void Map::moveObject(int nx, int ny, Entity* obj) {
    
    int dx = obj->x + nx;
    int dy = obj->y + ny;

    if (!isInside(dx, dy)) return;

    //Push back the object to the target vector
    grid[idx(dx, dy)].push_back(obj);

    //Erase existing object in the previous vector
    grid[idx(obj->x, obj->y)].erase(
        std::remove_if(grid[idx(obj->x, obj->y)].begin(), grid[idx(obj->x, obj->y)].end(), 
            [obj](Entity* e) {
                return e == obj;
        }),
        grid[idx(obj->x, obj->y)].end()
    );

    obj->x = dx;
    obj->y = dy;
}

void Map::movePlayer(int key) {
  //TODO Add in the Cursor implementation and movement   
    Entity* player = findPlayer();
    if (!player) return;

    switch (key) {
        case KEY_LEFT: moveObject(0, -1, player); break;
        case KEY_RIGHT: moveObject(0, 1, player); break;
        case KEY_UP: moveObject(-1, 0, player); break;
        case KEY_DOWN: moveObject(1, 0, player); break;
    }
}
