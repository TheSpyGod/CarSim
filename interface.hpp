#pragma once

#include <vector>

class Cursor;

class Interface {
public:
 
    void printMap(std::vector<char> map, int width);

    void printObject(char distance);

    void printScene(Cursor& c, std::vector<char> map);
};

