//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_MAP_H
#define GRA_MAP_H
#include "Tile.h"

class Map {
public:
    Map(int _width, int _height);
    Tile *getTile(int x, int y);
    int getWidth();
    int getHeight();
    void update();
    void makeHigherLevelOfWater();
private:
    int width, height;
    Tile ***tiles;
    void changingToWater(Tile*, Tile*);
};


#endif //GRA_MAP_H
