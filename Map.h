//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_MAP_H
#define GRA_MAP_H
#include "Tile.h"

class Map {
public:
    Map(int _width, int _height);
    ~Map();
    Tile *getTile(int x, int y);
    int getWidth();
    int getHeight();
    void update();
    bool changingToWater(Tile*, Tile*);
    void setWaterLevel(int level);
private:
    int width, height;
    Tile ***tiles;
};


#endif //GRA_MAP_H
