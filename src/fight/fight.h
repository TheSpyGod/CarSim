#pragma once
#include "../entities/entity.hpp"
#include "draw_fight.h"

struct FightState {
    Entity* player = nullptr;
    Entity* enemy = nullptr;
    bool playerTurn = true;
    float timer = 0.0f;
    float attackDelay = 0.5f;
    bool fightOver = true;
};


class Fight {
    drawFight df;

public:
    FightState fightState;

    bool isPlayerTurn(Entity* player, Entity* enemy);
    void startFight(Entity& player, Entity& enemy);
    void updateFight(float dt);
};
