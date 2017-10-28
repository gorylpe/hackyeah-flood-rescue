//
// Created by CLion on 28.10.2017.
//

#include "UIManager.h"
#include <iostream>

UIManager::UIManager() {

}

UIManager &UIManager::getSingleton() {
    static UIManager manager;
    return manager;
}

void UIManager::handleClick(Object *object) {
    std::cout << "Received a click at (" << object->getX() << ", " << object->getY() << " on '" << object->getName() << "'" << std::endl;
}

