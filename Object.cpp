//
// Created by Piotr on 28.10.2017.
//

#include "Object.h"
#include "GameManager.h"

void Object::kill() {
    active = false;
    GameManager::getSingleton().addLoss(worth);
}
