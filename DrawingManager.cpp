//
// Created by Piotr on 28.10.2017.
//

#include "DrawingManager.h"

DrawingManager::DrawingManager() {
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game");

    loadSprites();
}

void DrawingManager::loadSprites(){
    textureMap = new std::map<Tile::TILETYPE, sf::Texture*>();
    auto* texture = new sf::Texture();
    texture->loadFromFile("sprites/water.png");
    textureMap->insert(std::pair<>(Tile::TILETYPE::WATER, texture));

    texture = new sf::Texture();
    texture->loadFromFile("sprites/building.png");
    textureMap->insert(std::pair<>(Tile::TILETYPE::BUILDING, texture));

    texture = new sf::Texture();
    texture->loadFromFile("sprites/grass.png");
    textureMap->insert(std::pair<>(Tile::TILETYPE::GRASS, texture));

    texture = new sf::Texture();
    texture->loadFromFile("sprites/forest.png");
    textureMap->insert(std::pair<>(Tile::TILETYPE::FOREST, texture));

    texture = new sf::Texture();
    texture->loadFromFile("sprites/road.png");
    textureMap->insert(std::pair<>(Tile::TILETYPE::ROAD, texture));
}

void DrawingManager::draw(Map *map, std::vector<Object *> *objectsArray) {
    window->clear();


}

void DrawingManager::moveViewport(DrawingManager::MOVEDIR dir) {
    switch(dir){
        case LEFT:
            vx -= 1;
            if(vx < 0) vx = 0;
            break;
        case RIGHT:
            vx += 1;
            if(vx )
    }
}
