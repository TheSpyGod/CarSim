#include <utility>

class Entity {
private:
    std::pair<int, int> pos;
    
public:
    void set(int x, int y) {
        pos.first = x;
        pos.second = y;
    }

    std::pair<int, int> get() {
        return pos;
    }

      

};
