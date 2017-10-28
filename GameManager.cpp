//
// Created by pietrk01 on 10/28/2017.
//

#include "GameManager.h"

GameManager &GameManager::getSingleton() {
    static GameManager singleton;
    return singleton;
}

GameManager::GameManager() {
    isGameRunning = true;
    gameState = GAME;
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

}
