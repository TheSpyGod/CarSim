#include "engine.hpp"
#include "interface.hpp"
#include "Cursor.hpp"
#include "map.hpp"
class Loop {
private:
    Engine e;
    Map m;
    Interface f;
    Cursor c;
public:

    Loop() : m(15, 15), c(m.getSize()) {}

    void startLoop() {
        initscr();
        noecho();
        nodelay(stdscr, TRUE);
        curs_set(0);
        
        while (true) {
            f.printMap(m.getMap(), m.getWidth());  
            m.movePlayer(getch());
            f.printScene(c, m.getMap());
        }

        refresh();
        endwin();
    }


};
