#include "./fight.h"
// Print numbers on the screen for damage
// Do logic for damage taken and recieved
// If killed delete entity, or reuse entity for later
// inFight() flag for entities or just do a loop for the fight, which ends when one entity is killed 

//TODO pointer issue, fix it couse chat wont


bool Fight::isPlayerTurn(Entity* player, Entity* enemy) {
    if (player->initiative > enemy->initiative) return true;
    else return false;
}

void Fight::startFight(Entity& player, Entity& enemy) {
    fightState.player = player;
    fightState.enemy = enemy;
    fightState.playerTurn = isPlayerTurn(playerPtr, enemyPtr);
    fightState.timer = 0.0f;
    fightState.attackDelay = 0.5f;
    fightState.fightOver = false;
}

void Fight::updateFight(float dt) {

    fightState.timer += dt;

    if (fightState.timer >= fightState.attackDelay && !fightState.fightOver) {
        bool alive = fightState.enemy->takeDamage(fightState.player->dmg);
        printf("Damage: %d -> defender at %d,%d (alive=%d)\n", fightState.player->dmg,
               fightState.enemy->x, fightState.player->y, alive);

        fightState.timer = 0;
        if (!alive) fightState.fightOver = true;
    }

}
