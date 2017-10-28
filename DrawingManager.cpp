//
// Created by Piotr on 28.10.2017.
//

#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "DrawingManager.h"

DrawingManager::DrawingManager() {
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game");

    loadSprites();
}

void DrawingManager::loadSprites(){
    textureMap = new std::vector<sf::Texture*>();
    auto* texture = new sf::Texture();
    texture->loadFromFile("sprites/water.png");
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/building.png");
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/grass.png");
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/forest.png");
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/road.png");
    textureMap->push_back(texture);
}

void DrawingManager::draw(Map *map, std::vector<Object *> *objectsArray) {
    window->clear();

    for(int i = vx; i <= vx + vw; ++i){
        for(int j = vy; j <= vy + vh; ++j){
            sf::Sprite sprite;
            sprite.setTexture(*textureMap->at(map->getTile(i, j)->getTileType()));
            sprite.setPosition((i - vx) * tileWidth, (j - vy) * tileHeight);
            window->draw(sprite);
        }
    }

    window->display();
}

void DrawingManager::moveViewport(Map* map, DrawingManager::MOVEDIR dir) {
    switch(dir){
        case LEFT:
            vx -= 1;
            if(vx < 0) vx = 0;
            break;
        case RIGHT:
            vx += 1;
            if(vx + vw >= map->getWidth()) vx = map->getWidth() - vw - 1;
            break;
        case UP:
            vy -= 1;
            if(vy < 0) vy = 0;
            break;
        case DOWN:
            vy += 1;
            if(vy + vh >= map->getHeight()) vy = map->getHeight() - vh - 1;
            break;
    }
}
