//
// Created by Piotr on 28.10.2017.
//

#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "DrawingManager.h"
#include "UIManager.h"

DrawingManager::DrawingManager() {
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game");

    loadSprites();
}

void DrawingManager::loadSprites(){
    textureMap = new std::vector<sf::Texture*>();
    auto* texture = new sf::Texture();
    texture->loadFromFile("sprites/water.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/building.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/grass.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/forest.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/road.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/sandbags.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);

    texture = new sf::Texture();
    texture->loadFromFile("sprites/firetruck.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);
}

void DrawingManager::draw(Map *map, std::vector<Object *>* objectsArray) {
    window->clear();

    for(int i = vx; i <= vx + vw; ++i){
        for(int j = vy; j <= vy + vh; ++j){
            Tile* tile = map->getTile(i, j);
            sf::Sprite sprite;
            int x = i - vx;
            int y = j - vy;
            sprite.setTexture(*textureMap->at(tile->getTexture()));
            sprite.setPosition(x * tileWidth, y * tileHeight);
            sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
            window->draw(sprite);

            if(tile->getSandbagsUp()){
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                window->draw(sprite);
            }
            if(tile->getSandbagsDown()){
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setRotation(180);
                window->draw(sprite);
            }
            if(tile->getSandbagsLeft()){
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setRotation(90);
                window->draw(sprite);
            }
            if(tile->getSandbagsUp()){
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setRotation(270);
                window->draw(sprite);
            }

            for(int k = 0; k < objectsArray->size(); ++k){
                Object* object = objectsArray->at(k);
                x = object->getX() - vx;
                y = object->getY() - vy;
                sprite.setTexture(*textureMap->at(object->getTexture()));
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }
        }
    }

    UIManager::getSingleton().draw(window);

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

int DrawingManager::getViewportTileX(int mouseX) {
    return (mouseX / tileWidth) - vw;
}

int DrawingManager::getViewportTileY(int mouseY) {
    return (mouseY / tileHeight) - vh;
}
