//
// Created by CLion on 28.10.2017.
//

#include <cstring>
#include "Map.h"
#include "ObjectManager.h"
#include "GameManager.h"

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
            copy[i][j]->setSandbagsRight(tiles[i][j]->getSandbagsRight());
            copy[i][j]->setSandbagsLeft(tiles[i][j]->getSandbagsLeft());
            copy[i][j]->setSandbagsUp(tiles[i][j]->getSandbagsUp());
            copy[i][j]->setSandbagsDown(tiles[i][j]->getSandbagsDown());
        }
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            Tile* water = copy[i][j];
            if(water->getTexture() == DrawableObject::TEXTURE::WATER){
                if(i > 0){
                    Tile* notWater = getTile(i-1, j);
                    if(!notWater->getSandbagsRight() && !water->getSandbagsLeft()) {
                        if (changingToWater(water, notWater)) {
                            auto object = ObjectManager::getSingleton().getObjectAt(i-1, j);
                            if (object != nullptr) {
                                object->kill();
                            }
                        }
                    }
                }
                if(j > 0){
                    Tile* notWater = getTile(i, j-1);
                    if(!notWater->getSandbagsDown() && !water->getSandbagsUp()) {
                        if (changingToWater(water, notWater)) {
                            auto object = ObjectManager::getSingleton().getObjectAt(i, j-1);
                            if (object != nullptr) {
                                object->kill();
                            }
                        }
                    }
                }
                if(i < width-1){
                    Tile* notWater = getTile(i+1, j);
                    if(!notWater->getSandbagsLeft() && !water->getSandbagsRight()) {
                        if (changingToWater(water, notWater)) {
                            auto object = ObjectManager::getSingleton().getObjectAt(i+1, j);
                            if (object != nullptr) {
                                object->kill();
                            }
                        }
                    }
                }
                if(j < height-1){
                    Tile* notWater = getTile(i, j+1);
                    if(!notWater->getSandbagsUp() && !water->getSandbagsDown()) {
                        if (changingToWater(water, notWater)) {
                            auto object = ObjectManager::getSingleton().getObjectAt(i, j+1);
                            if (object != nullptr) {
                                object->kill();
                            }
                        }
                    }
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

bool Map::changingToWater(Tile* water, Tile* notWater) {
    bool changed = false;
    if (notWater->getTexture() != DrawableObject::TEXTURE::WATER) {
        if (notWater->getHeight() < water->getHeight()) {
            notWater->setTexture(DrawableObject::TEXTURE::WATER);
            changed = true;
            if (notWater->getTexture() != DrawableObject::TEXTURE::BUILDING) {
                GameManager::getSingleton().addLoss(10);
            }
        }
    }
    notWater->setHeight(water->getHeight());
    return changed;
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

void Map::setWaterLevel(int level) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (tiles[i][j]->getTexture() == DrawableObject::TEXTURE::WATER) {
                tiles[i][j]->setHeight(level);
            }
        }
    }
}

