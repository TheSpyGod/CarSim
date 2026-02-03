#include "draw_fight.h"

void drawFight::drawDamage(int damageNumber) {
        // Appear and float up slowly, then dissapear and reuse by resetting its state and change the damage number
        DrawText(std::to_string(damageNumber).c_str(), 400, 500, 20, RED);
}
