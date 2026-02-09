#include "./fight.h"
// Print numbers on the screen for damage
// Do logic for damage taken and recieved
// If killed delete entity, or reuse entity for later
// inFight() flag for entities or just do a loop for the fight, which ends when one entity is killed 

//TODO pointer issue, fix it couse chat wont

const bool Fight::isPlayerTurn(Entity& player, Entity& enemy) {
    if (player.initiative > enemy.initiative) return true;
    else return false;
}

void Fight::startFight(Entity& player, Entity& enemy) {
    if (isPlayerTurn(player, enemy)) {
        fightState.attacker = &player;
        fightState.defender = &enemy;
    } else {
        fightState.attacker = &enemy;
        fightState.defender = &player;
    }
    fightState.timer = 0.0f;
    fightState.attackDelay = 0.5f;
    fightState.fightOver = false;
}

void Fight::updateFight(float dt) {
    fightState.timer += dt;

    if (fightState.timer >= fightState.attackDelay && !fightState.fightOver) {
        fightState.fightOver = !fightState.attacker->takeDamage(fightState.defender->dmg);

        printf("Damage: %d -> defender at %d,%d (alive=%d)\n", fightState.attacker->dmg,
               fightState.defender->x, fightState.attacker->y, !fightState.fightOver);

        fightState.timer = 0;

    }
}
