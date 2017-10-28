//
// Created by Piotr on 28.10.2017.
//

#include <fstream>
#include "MapLoader.h"

Map *MapLoader::loadMap(std::string filename) {
    std::ifstream file;
    file.open(filename);
    int width, height;
    file >> width >> height;
    auto* map = new Map(width, height);

    int type;

    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            file >> type >> height;
            Tile* tile = map->getTile(i, j);
            tile->setTileType((Tile::TILETYPE)type);
            tile->setHeight(height);
        }
    }

    return map;
}
