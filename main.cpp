#include "GameManager.h"

int main() {
    GameManager *gameManager = &GameManager::getSingleton();
    gameManager->setFrameTime(16);
    gameManager->mainLoop();
    return 0;
}