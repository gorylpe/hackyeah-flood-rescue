//
// Created by pietrk01 on 10/28/2017.
//

#include <iostream>
#include "GameManager.h"
#include "ObjectManager.h"
#include "MapLoader.h"
#include "UIManager.h"

GameManager &GameManager::getSingleton() {
    static GameManager singleton;
    return singleton;
}

GameManager::GameManager() {
    isGameRunning = true;
    gameState = GAME;
    map = MapLoader::loadMap("map1.txt");
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
    handleEvents();
    DrawingManager::getSingleton().draw(map, ObjectManager::getSingleton().getObjects());
}

void GameManager::handleEvents() {
    DrawingManager *drawingManager = &DrawingManager::getSingleton();
    sf::Window *window = drawingManager->getWindow();
    sf::Event e;
    while (window->pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window->close();
                isGameRunning = false;
                break;
            case sf::Event::KeyPressed:
                switch (e.key.code) {
                    case sf::Keyboard::Space:
                        doObjectsIteration();
                        break;
                    case sf::Keyboard::Left:
                        drawingManager->moveViewport(map, DrawingManager::LEFT);
                        break;
                    case sf::Keyboard::Right:
                        drawingManager->moveViewport(map, DrawingManager::RIGHT);
                        break;
                    case sf::Keyboard::Up:
                        drawingManager->moveViewport(map, DrawingManager::UP);
                        break;
                    case sf::Keyboard::Down:
                        drawingManager->moveViewport(map, DrawingManager::DOWN);
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                switch (e.mouseButton.button) {
                    case sf::Mouse::Left:
                        UIManager::getSingleton().handleClick(e.mouseButton.x, e.mouseButton.y);
                        break;
                    default:
                        break;
                }
                break;
        }
    }
}

void GameManager::resetMap(){
    delete map;
    map = MapLoader::loadMap("map1.txt");
    ObjectManager::resetObjects();
}

void GameManager::doObjectsIteration(){
    map->update();
}
