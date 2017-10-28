//
// Created by pietrk01 on 10/28/2017.
//

#include <iostream>
#include "GameManager.h"
#include "ObjectManager.h"
#include "MapLoader.h"

GameManager &GameManager::getSingleton() {
    static GameManager singleton;
    return singleton;
}

GameManager::GameManager() {
    isGameRunning = true;
    gameState = GAME;
    map = MapLoader::loadMap("map1.txt");
    std::cout << map->getTile(0, 0)->getTileType() << std::endl;
}

GameManager::~GameManager() {
}

void GameManager::mainLoop() {
    sf::Clock frameClock;
    while(isGameRunning){
        frameClock.restart();
        switch(gameState){
            case GAMESTATE::GAME:
                gameLoop();
                sf::Time loopTime = frameClock.restart();
                sf::sleep(frameTime - loopTime);
                break;
        }
    }
}

void GameManager::setFrameTime(int time) {
    frameTime = sf::milliseconds(time);
}

void GameManager::gameLoop() {
    sf::Event e;
    DrawingManager *drawingManager = &DrawingManager::getSingleton();
    sf::Window *window = drawingManager->getWindow();
    while (window->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window->close();
                isGameRunning = false;
                break;
            case sf::Event::KeyPressed:
                switch (e.key.code) {
                    case sf::Keyboard::Space:
                       map->update();
                }
        }
    }
    drawingManager->draw(map, ObjectManager::getSingleton().getObjects());
}
