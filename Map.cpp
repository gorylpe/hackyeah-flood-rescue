//
// Created by CLion on 28.10.2017.
//

#include "Map.h"
Map::Map(int _width, int _height):
        width(_width),
        height(_height) {

}

unsigned int Map::getWaterLevel(int x, int y) {
    return waterLevels[x][y];
}

void Map::setWaterLevel(int x, int y, int level) {
   waterLevels[x][y] = level;
}
