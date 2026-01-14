#include "loop.hpp"
#include "../window/window.h"
#include <random>
#include <ctime>

Loop::Loop() : m(15, 15) {}

void Loop::startLoop() {
    Window win;
    win.init();
}
