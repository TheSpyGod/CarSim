#include "interface.hpp"
#include "curses.h"
#include "cursor.hpp"

void Interface::printMap(std::vector<char> map, int width) {
    for (int i = 0; i < map.size(); i++) {
        int count = i / width;
        int count2 = i % width;
        mvaddch(count2, count ,map[i]);
        count++;
        count2++;
    }
}

void Interface::printObject(char distance) {
    //TODO first the middle, then two from that, and two from that x = half, x-1 & x+1. LGTM DONE!
    int row = 0, col = 0; 
    
    int middleR = 0, middleL = 0;
    
    int multiplier = 0;

    bool mid = false;

    getmaxyx(stdscr, row, col);

    if (distance == 'c') {
        middleR = col / 2;
        middleL = col / 2;
        multiplier = 2;
    } else if (distance == 'f') {
        middleR = col / 3;
        middleR = col / 3;
        multiplier = 1;
    }

    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            mvaddch(i,middleR,'*');
            mvaddch(i,middleL,'*');
        }

        if (i == (row / 2)) 
            mid = true;

        if (mid) {
            middleR -= multiplier;
            middleL += multiplier;   
        } else {
            middleR += multiplier;
            middleL -= multiplier;
        }
    }

    refresh();
    
}

void Interface::printScene(Cursor& c, std::vector<char> map) {
    char value = map[c.getPos()];
    
    switch (value) {
        case '&':
        printObject('c');
        break;
        default:
        clear();
    }   
}
