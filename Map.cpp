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

void Map::update() {
  for(int i = 0; i < width; i++){
     for(int j = 0; j < height; j++){
         Tile* water = getTile(i, j);
         if(water->getTileType() == Tile::TILETYPE::WATER){
             if(i > 0){
                 Tile* notWater = getTile(i-1, j);
                 changingToWater(water, notWater);
                 }
             if(j > 0){
                 Tile* notWater = getTile(i, j-1);
                 changingToWater(water, notWater);
             }
             if(i < width-1){
                Tile* notWater = getTile(i+1, j);
                 changingToWater(water, notWater);
             }
             if(j < height-1){
                 Tile* notWater = getTile(i, j+1);
                 changingToWater(water, notWater);
             }
             }
         }
     }
 }

void Map::changingToWater(Tile* _water, Tile* _notWater) {
    if (_notWater->getTileType() != Tile::TILETYPE::WATER) {
        if (_notWater->getHeight() < _water->getHeight()) {
            _notWater->setTileType(Tile::TILETYPE::WATER);
        }
    }
}

