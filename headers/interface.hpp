#pragma once

#include <vector>

class Interface {
public:
 
    void printMap(std::vector<char> map, int width);

    void printObject(char distance);

    void printScene(std::vector<char> map);
};

