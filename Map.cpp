//
// Created by CLion on 28.10.2017.
//

#include "Map.h"
Map::Map(int _width, int _height):
        width(_width),
        height(_height) {
    tiles = new Tile**[width];
    for (int i = 0; i < height; i++) {
      tiles[i] = new Tile*[height];
    }
}

Tile *Map::getTile(int x, int y) {
    return tiles[x][y];
}

int Map::getWidth() {
    return width;
}

int Map::getHeight() {
    return height;
}

