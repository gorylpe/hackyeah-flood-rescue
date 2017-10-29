//
// Created by Piotr on 28.10.2017.
//

#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "DrawingManager.h"
#include "UIManager.h"
#include "ObjectFiretruck.h"
#include "ObjectManager.h"
#include "GameManager.h"

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

    texture = new sf::Texture();
    texture->loadFromFile("sprites/helicopter.png");
    texture->setSmooth(true);
    textureMap->push_back(texture);
}

void DrawingManager::draw(Map *map, std::vector<ObjectFirestation*>* firestationsArray) {
    window->clear();

    int istart = vx, istop = std::min(vx+vw, GameManager::getSingleton().getMap()->getWidth() - 1);
    int jstart = vy, jstop = std::min(vy+vh, GameManager::getSingleton().getMap()->getHeight() - 1);
    for(int i = istart; i <= istop; ++i){
        for(int j = jstart; j <= jstop; ++j){
            Tile* tile = map->getTile(i, j);
            sf::Sprite sprite;
            int x = std::max(i - vx, 0);
            int y = std::max(j - vy, 0);
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
        }
    }

    sf::Sprite sprite;
    for(int k = 0; k < firestationsArray->size(); ++k) {
        ObjectFirestation *firestation = firestationsArray->at(k);
        int x = std::max(firestation->getX() - vx, 0);
        int y = std::max(firestation->getY() - vy, 0);
        if (firestation->getActive()) {
            sf::Sprite sprite;
            sprite.setTexture(*textureMap->at(firestation->getTexture()));
            sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width,
                            1.0 * tileHeight / sprite.getLocalBounds().height);
            sprite.setPosition(x * tileWidth, y * tileHeight);
            window->draw(sprite);
        }

        std::vector<ObjectFiretruck *> *objectsFiretrucks = firestation->getFiretrucks();
        for (ObjectFiretruck *firetruck : *objectsFiretrucks) {
            if (firetruck->getActive()) {
                std::vector<sf::Vector2i> *path = firetruck->getPath();
                if (path != nullptr) {
                    for (sf::Vector2i v : *path) {
                        int pathX = v.x - vx;
                        int pathY = v.y - vy;
                        sf::CircleShape shape(3);
                        shape.setFillColor(sf::Color::Yellow);
                        shape.setPosition((pathX + 0.5) * tileWidth - 3, (pathY + 0.5) * tileHeight - 3);
                        window->draw(shape);
                    }
                }
                int fx = firetruck->getX() - vx;
                int fy = firetruck->getY() - vy;
                if (fx != x || fy != y) {
                    sf::Sprite sprite;
                    sprite.setTexture(*textureMap->at(firetruck->getTexture()));
                    sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width,
                                    1.0 * tileHeight / sprite.getLocalBounds().height);
                    sprite.setPosition(fx * tileWidth, fy * tileHeight);
                    window->draw(sprite);
                }
            }
        }
        std::vector<ObjectHelicopter *> *objectsHelicopters = firestation->getHelicopters();
        for (ObjectHelicopter *helicopter : *objectsHelicopters) {
            std::vector<sf::Vector2i> *path = helicopter->getPath();
            if (path != nullptr) {
                for (sf::Vector2i v : *path) {
                    int pathX = v.x - vx;
                    int pathY = v.y - vy;
                    sf::CircleShape shape(3);
                    shape.setFillColor(sf::Color::Yellow);
                    shape.setPosition((pathX + 0.5) * tileWidth - 3, (pathY + 0.5) * tileHeight - 3);
                    window->draw(shape);
                }
            }
            int fx = helicopter->getX() - vx;
            int fy = helicopter->getY() - vy;
            if (fx != x || fy != y) {
                sf::Sprite sprite;
                sprite.setTexture(*textureMap->at(helicopter->getTexture()));
                sprite.setScale(1.0 * tileWidth / sprite.getLocalBounds().width,
                                1.0 * tileHeight / sprite.getLocalBounds().height);
                sprite.setPosition(fx * tileWidth, fy * tileHeight);
                window->draw(sprite);
            }
        }
    }

    for(int i = istart; i <= istop; ++i) {
        for (int j = jstart; j <= jstop; ++j) {
            Tile* tile = map->getTile(i, j);
            int x = i - vx;
            int y = j - vy;
            if (debugMode) {
                sf::Text coords;
                coords.setFont(*font);
                coords.setCharacterSize(10);
                coords.setFillColor(sf::Color::White);
                coords.setString(std::to_string(i) + "x" + std::to_string(j));
                coords.setPosition(x * tileWidth, y * tileHeight);
                window->draw(coords);
            }

            if (showHeightLevels) {
                sf::Text height;
                height.setFont(*font);
                height.setCharacterSize(24 * tileWidth / 40);
                height.setFillColor(sf::Color::Black);
                height.setOutlineColor(sf::Color::White);
                height.setOutlineThickness(2.0 * tileWidth / 40);
                height.setString(std::to_string(tile->getHeight()));
                height.setPosition((x + 0.25) * tileWidth, (y + 0.25) * tileHeight);
                window->draw(height);
            }
        }
    }

    UIManager::getSingleton().draw(window);

    sf::Text pauseState;
    pauseState.setFont(*font);
    pauseState.setFillColor(sf::Color::Green);
    pauseState.setCharacterSize(16);
    pauseState.setPosition(20, windowHeight - 20);
    std::string message;
    if (GameManager::getSingleton().isPaused()) {
        message = "SPACE: unpause";
    } else {
        message = "SPACE: pause";
    }
    pauseState.setString(message);
    window->draw(pauseState);

    int countdown = GameManager::getSingleton().getFloodCountdown();
    if (countdown > 0) {
        sf::Text countdown;
        countdown.setFont(*font);
        countdown.setFillColor(sf::Color::Red);
        countdown.setCharacterSize(16);
        countdown.setPosition(20, windowHeight - 40);
        std::string message = "Flood starts in: ";
        int secondsTillStart = GameManager::getSingleton().getFloodCountdown() * GameManager::getSingleton().getTickTime().asSeconds();
        message += std::to_string(secondsTillStart) + std::string(" seconds");
        countdown.setString(message);
        window->draw(countdown);
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
            if(vx + vw >= map->getWidth()) vx = std::max(map->getWidth() - vw - 1, 0);
            break;
        case UP:
            vy -= 1;
            if(vy < 0) vy = 0;
            break;
        case DOWN:
            vy += 1;
            if(vy + vh >= map->getHeight()) vy = std::max(map->getHeight() - vh - 1, 0);
            break;
    }
}

int DrawingManager::getViewportTileX(int mouseX) {
    return (mouseX / tileWidth) + vx;
}

int DrawingManager::getViewportTileY(int mouseY) {
    return (mouseY / tileHeight) + vy;
}

void DrawingManager::setZoomLevel(Map* map, int i) {
    switch(i){
        case 0:
            tileHeight = 20;
            tileWidth = 20;
            break;
        case 1:
            tileHeight = 30;
            tileWidth = 30;
            break;
    }
    vw = windowWidth / tileWidth;
    vh = windowHeight / tileHeight;

    if(vx + vw >= map->getWidth()) vx = map->getWidth() - vw - 1;
    if(vy + vh >= map->getHeight()) vy = map->getHeight() - vh - 1;
    if(vx < 0) vx = 0;
    if(vy < 0) vy = 0;
}



