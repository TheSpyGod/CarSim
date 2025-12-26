#include <vector>
#include <utility>
class Map {
private:
    const int width, height;
    std::vector<char> tiles;

public:

    Map(int w, int h) : height(h), width(w), tiles(w * h) {}
    
    char getItem(int x, int y) const {
        return tiles[y * width + x];
    }

    std::vector<char> getMap() {
        return tiles;
    }

    int getWidth() {
        return width;
    }

    std::pair<int, int> getItemPos(char target) const {
        for (int i = 0; i < tiles.size(); ++i) {
            if (tiles[i] == target) {
                int x = i % width;
                int y = i / width;
                return std::make_pair(x,y);
            }
        }
        return {0,0};
    }
    
    void set(int x, int y, char value) {
        tiles[y * width + x] = value;
    }
    
    int getSize() {
        return height * width;
    }

    int checkIfExists(char icon) {
        for (char c : tiles) {
            if (c == icon)
                return true;
        }
        return false;
    }

    //TODO Fix logic for movement, when hitting a corner it doesnt stop
    bool checkIfCanMove(int x, int y) {
        return (x >= 0 && x < height) &&
               (y >= 0 && y < width);
    }

    void move(int x, int y, char icon) {
        if (checkIfCanMove(x,y))
            set(x,y,icon);
    }

    bool checkScene(Cursor c) {
        // IF the cursor location is empty do NOT display ANY scene.
        if (tiles[c.getX() * c.getY()] != '0')
            //Space in cursor is NOT empty!
            return true;
        else
            return false;
    }

    void movePlayer(int direction/*, Cursor& c*/) {
        //locate player self explanetory
        std::pair<int, int> playerPos = getItemPos('p');
        
        switch (direction) {
            case 'w':
                move(playerPos.first-1, playerPos.second, 'p');
                move(playerPos.first, playerPos.second,'0');
                // Set cursor pos
                //c.set(x-2,y);
            break;

            case 's':
                move(playerPos.first+1, playerPos.second, 'p');
                move(playerPos.first, playerPos.second,'0');
                //Set cursor pos
                //c.set(x+2,y);

            break;

            case 'a':
                move(playerPos.first, playerPos.second-1, 'p');
                move(playerPos.first, playerPos.second,'0');
                //Set cursor pos
                //c.set(x, y-2);

            break;

            case 'd':
                move(playerPos.first, playerPos.second+1, 'p');
                move(playerPos.first, playerPos.second,'0');
                //Set cursor pos
                //c.set(x,y+2);
            break;
        }
    }
};
