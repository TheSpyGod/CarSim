#include "headers/loop.hpp"
#include "headers/curses.h"

Loop::Loop() : m(15, 15) {}

void Loop::startLoop() {
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    
    while (true) {
        f.printMap(m.getMap(), m.getWidth());  
        m.movePlayer(getch());
        f.printScene(m.getMap());
    }

    refresh();
    endwin();
}
