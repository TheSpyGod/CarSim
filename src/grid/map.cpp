//TODO
// - Fix player movement 
// - Implemnet proper Entities
#include "./map.hpp"


Map::Map(int w, int h, Fight& fightRef) : width(w), height(h), grid(width * height), fight(fightRef) {
    srand(time(0));

    entities.resize(rand() % 10 + 1);
};

//Map::Map() {}
//TODO 
// 
// FIXME Overcomplicated Syntax + Method logic

const std::vector<Entity*> Map::getEntitiesAt(int x, int y) const {
    int coords = idx(x,y);
    return grid[coords];
}

const std::vector<Entity*> Map::getPlayerCell() const {
    return grid[idx(entities[0].x, entities[0].y)];
}

bool Map::isInsideGrid(Entity& e) const {
    return (e.x >= 0 && e.x < height) && (e.y >= 0 && e.y < width);
}

void Map::setEntity(Entity& e) {
    if (isInsideGrid(e))

    grid[idx(e.x, e.y)]
        .push_back(&e);
}

const std::vector<std::vector<Entity*>>& Map::getGrid() const { return grid; }

const int Map::getWidth() const { return width; }

void Map::computeGrid() {
    for (auto& cell : grid) cell.clear(); 

    for (auto& entity : entities) {
        setEntity(entity);
    }
}

void Map::randomize() {
    if (entities.empty()) return;

    // Assign player the first spot
    entities[0].type = EntityType::Player;
    entities[0].dmg = 35;
    entities[0].x = 0;
    entities[0].y = 0;
    for (auto& entity : entities) {
        if (entity.type == EntityType::Player) continue;
        entity.type = (rand() % 2 == 0) ? EntityType::Enemy : EntityType::Item;
        entity.x = rand() % width;
        entity.y = rand() % height;
    }
}

bool Map::isPlayerAlive() {
    Entity player = entities[0];
    if (player.health <= 0) return false;
    return true;
}

void Map::checkCollision() {
    if (!fight.fightState.fightOver) return;

    Entity* targetEntity = nullptr;
    
    Entity& player = entities[0];

    for (auto& entity : entities) {
        if (&entity == &player) continue;
        if (entity.x == player.x && entity.y == player.y) {
            targetEntity = &entity;
            break;
        }
    }

    if (targetEntity && targetEntity->type == EntityType::Enemy) {
        if (targetEntity->health > 0)
        fight.startFight(player, *targetEntity);
 
        if (targetEntity->health <= 0) {
            targetEntity->x = -1;
            targetEntity->y = -1;
        }

        //printf("Player colided at %d,%d\n", entities[0].x, entities[0].y);
    }
}

void Map::moveObject(int nx, int ny, Entity& obj) {
    
    int dx = obj.x + nx;
    int dy = obj.y + ny;

    Entity newLocation;
    newLocation.x = dx;
    newLocation.y = dy;

    if (!isInsideGrid(newLocation)) return;

    obj.x = dx;
    obj.y = dy;
}

void Map::movePlayer(int key) {
    if (entities.empty()) return;
      
    auto& player = entities[0];
    
    printf("Player location - x: %d , y: %d", player.x, player.y);

    switch (key) {
        case KEY_LEFT: moveObject(0, -1, player); break;
        case KEY_RIGHT: moveObject(0, 1, player); break;
        case KEY_UP: moveObject(-1, 0, player); break;
        case KEY_DOWN: moveObject(1, 0, player); break;
    }

}
