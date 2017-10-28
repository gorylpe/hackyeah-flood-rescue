//
// Created by CLion on 28.10.2017.
//

#include <cstring>
#include "Map.h"
Map::Map(int _width, int _height):
        width(_width),
        height(_height) {
    tiles = new Tile**[width];
    for (int i = 0; i < width; i++) {
        tiles[i] = new Tile*[height];
        for(int j = 0; j < height; ++j){
            tiles[i][j] = new Tile();
        }
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
    Tile*** copy = new Tile**[width];
    for (int i = 0; i < width; i++) {
        copy[i] = new Tile*[height];
        for(int j = 0; j < height; ++j){
            copy[i][j] = new Tile();
            copy[i][j]->setHeight(tiles[i][j]->getHeight());
            copy[i][j]->setTexture(tiles[i][j]->getTexture());
        }
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            Tile* water = copy[i][j];
            if(water->getTexture() == DrawableObject::TEXTURE::WATER){
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
    for (int i = 0; i < width; i++) {
        for(int j = 0; j < height; ++j){
            delete copy[i][j];
        }
        delete copy[i];
    }
    delete copy;
}

void Map::changingToWater(Tile* water, Tile* notWater) {
    if (notWater->getTexture() != DrawableObject::TEXTURE::WATER) {
        if (notWater->getHeight() < water->getHeight()) {
            notWater->setTexture(DrawableObject::TEXTURE::WATER);
        }
    }
    notWater->setHeight(water->getHeight());
}

Map::~Map() {
    for (int i = 0; i < width; i++) {
        for(int j = 0; j < height; ++j){
            delete tiles[i][j];
        }
        delete tiles[i];
    }
    delete tiles;
}

