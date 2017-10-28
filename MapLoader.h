//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_MAPLOADER_H
#define GRA_MAPLOADER_H

#include <string>
#include "Map.h"

class MapLoader {
public:
    static Map* loadMap(std::string filename);
};


#endif //GRA_MAPLOADER_H
