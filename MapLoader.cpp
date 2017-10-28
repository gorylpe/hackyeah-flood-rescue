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

    int type;

    for(int i = 0; i < mapWidth; ++i){
        for(int j = 0; j < mapHeight; ++j){
            file >> type >> mapHeight;
            Tile* tile = map->getTile(j, i);
            tile->setHeight(mapHeight);
            tile->setTileType(static_cast<Tile::TILETYPE>(type));
        }
    }

    return map;
}
