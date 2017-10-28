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
    Map* map = new Map(width, height);

}
