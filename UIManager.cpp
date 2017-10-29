//
// Created by CLion on 28.10.2017.
//

#include "UIManager.h"
#include "ObjectManager.h"
#include "UIStateDefault.h"
#include <iostream>

UIManager::UIManager() {
    font = new sf::Font();
    font->loadFromFile("Roboto-Regular.ttf");

    currentState = new UIStateDefault();
}

UIManager &UIManager::getSingleton() {
    static UIManager manager;
    return manager;
}

void UIManager::handleClick(int x, int y) {
    currentState->handleClick(x, y);
}

void UIManager::draw(sf::RenderWindow *window) {
    currentState->draw(window);
}

void UIManager::update() {
    if(nextState != nullptr){
        delete currentState;
        currentState = nextState;
        nextState = nullptr;
    }
}

