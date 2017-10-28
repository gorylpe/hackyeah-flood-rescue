//
// Created by CLion on 28.10.2017.
//

#include "UIManager.h"
#include "ObjectManager.h"
#include <iostream>

UIManager::UIManager() {
    elements = new std::vector<UIElement*>();
}

UIManager &UIManager::getSingleton() {
    static UIManager manager;
    return manager;
}

void UIManager::handleClick(int x, int y) {
    auto *drawingManager = &DrawingManager::getSingleton();
    int _x = drawingManager->getViewportTileX(x);
    int _y = drawingManager->getViewportTileY(y);
    Object *object = ObjectManager::getSingleton().getObjectAt(_x, _y);
    if (object != nullptr) {
        std::cout << "Received a click at (" << object->getX() << ", " << object->getY() << " on '" << object->getName()
                  << "'" << std::endl;
    }
}

void UIManager::draw(sf::RenderWindow *window) {
    for (int i = 0; i < elements->size(); i++) {
        (*elements)[i]->draw(window);
    }
}

void UIManager::addElement(UIElement *element) {
    elements->push_back(element);
}

