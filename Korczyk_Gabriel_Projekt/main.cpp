#include "./src/game/loop.hpp"
#include <cstdlib>
#include <ctime>
int main() {
    srand(time(0));
    Loop l;
    l.startLoop();
    return 0;
}
