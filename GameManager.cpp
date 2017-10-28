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
    while(isGameRunning){

        switch(gameState){
            case GAME:
            case MENU:
        }
    }
}
