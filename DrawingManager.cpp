//
// Created by Piotr on 28.10.2017.
//

#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include "DrawingManager.h"
#include "UIManager.h"

DrawingManager::DrawingManager() {
    window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game");

    font = new sf::Font();
    font->loadFromFile("Roboto-Regular.ttf");

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
    texture->loadFromFile("sprites/firestation.png");
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
                sf::Sprite sprite;
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
                sprite.setRotation(180);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }
            if(tile->getSandbagsDown()){
                sf::Sprite sprite;
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }
            if(tile->getSandbagsLeft()){
                sf::Sprite sprite;
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(0, sprite.getLocalBounds().height);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setRotation(90);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }
            if(tile->getSandbagsRight()){
                sf::Sprite sprite;
                sprite.setTexture(*textureMap->at(DrawableObject::TEXTURE::SANDBAGS));
                sprite.setOrigin(sprite.getLocalBounds().width, 0);
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width, 1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setRotation(270);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }

            sf::Text coords;
            coords.setFont(*font);
            coords.setCharacterSize(10);
            coords.setFillColor(sf::Color::White);
            coords.setString(std::to_string(i) + "x" + std::to_string(j));
            coords.setPosition(x * tileWidth, y * tileWidth);
            window->draw(coords);

            sf::Text height;
            height.setFont(*font);
            height.setCharacterSize(12);
            height.setFillColor(sf::Color::Black);
            height.setString(std::to_string(tile->getHeight()));
            height.setPosition((x + 0.5) * tileWidth, (y + 0.5) * tileWidth);
            window->draw(height);

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
    return (mouseX / tileWidth) - vx;
}

int DrawingManager::getViewportTileY(int mouseY) {
    return (mouseY / tileHeight) - vy;
}
