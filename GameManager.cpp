//
// Created by pietrk01 on 10/28/2017.
//

#include "GameManager.h"
#include "ObjectManager.h"

GameManager &GameManager::getSingleton() {
    static GameManager singleton;
    return singleton;
}

GameManager::GameManager() {
    isGameRunning = true;
    gameState = GAME;
    map = new Map(50, 50);
}

GameManager::~GameManager() {
}

void GameManager::mainLoop() {
    sf::Clock frameClock;
    while(isGameRunning){
        frameClock.restart();
        switch(gameState){
            case GAME:
                gameLoop();
                sf::Time loopTime = frameClock.restart();
                sf::sleep(frameTime - loopTime);
                break;
            case MENU:
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
