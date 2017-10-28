//
// Created by pietrk01 on 10/28/2017.
//

#include "GameManager.h"

GameManager &GameManager::getSingleton() {
    static GameManager singleton;
    return singleton;
}

GameManager::GameManager() {

}

GameManager::~GameManager() {

}

void GameManager::mainLoop() {

}
