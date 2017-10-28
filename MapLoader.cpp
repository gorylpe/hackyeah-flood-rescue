//
// Created by Piotr on 28.10.2017.
//

#include <fstream>
#include <iostream>
#include "MapLoader.h"

Map* MapLoader::loadMap(std::string filename) {
    std::ifstream file;
    file.open(filename);
    int mapWidth, mapHeight;
    file >> mapWidth >> mapHeight;
    auto* map = new Map(mapWidth, mapHeight);

    int type, height;
    for(int j = 0; j < mapHeight; ++j){
        for(int i = 0; i < mapWidth; ++i){
            file >> type >> height;
            Tile* tile = map->getTile(i, j);
            tile->setHeight(height);
            tile->setTexture(static_cast<DrawableObject::TEXTURE>(type));
        }
    }

    map->getTile(2,2)->setSandbagsDown(true);
    map->getTile(2,2)->setSandbagsUp(true);
    map->getTile(3,6)->setSandbagsLeft(true);
    map->getTile(2,2)->setSandbagsRight(true);

    map->getTile(6, 5)->setSandbagsUp(true);
    map->getTile(6, 5)->setSandbagsDown(true);
    map->getTile(6, 5)->setSandbagsLeft(true);

    return map;
}
