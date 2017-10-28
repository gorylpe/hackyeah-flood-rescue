//
// Created by Piotr on 28.10.2017.
//

#include "DrawingManager.h"

void DrawingManager::draw(Map *map, std::vector<Object *> *objectsArray) {

}

DrawingManager::DrawingManager() {
    textureMap = new std::map<Tile::TILETYPE, sf::Texture>();
}
