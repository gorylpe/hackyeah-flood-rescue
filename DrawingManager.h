//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_DRAWINGMANAGER_H
#define GRA_DRAWINGMANAGER_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include "Map.h"
#include "Object.h"
#include "Tile.h"

class DrawingManager {
    DrawingManager();
    DrawingManager(const DrawingManager&){};

    std::map<Tile::TILETYPE, sf::Texture>* textureMap;
public:
    static DrawingManager& getSingleton(){
        static DrawingManager singleton;
        return singleton;
    }

    void draw(Map* map, std::vector<Object*>* objectsArray);
};


#endif //GRA_DRAWINGMANAGER_H
