//
// Created by CLion on 28.10.2017.
//

#include "UIManager.h"
#include "ObjectManager.h"
#include "UIStateDefault.h"
#include "UITextLabel.h"
#include "GameManager.h"
#include <iostream>

UIManager::UIManager() {
    font = new sf::Font();
    font->loadFromFile("Roboto-Regular.ttf");

    currentState = new UIStateDefault();

    lossText = new UITextLabel(10, 10, 200, 30, "Loss: 0$");
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
    lossText->draw(window);
}

void UIManager::update() {
    if(nextState != nullptr){
        delete currentState;
        currentState = nextState;
        nextState = nullptr;
    }
}

void UIManager::updateLoss(int loss) {
    lossText->setText("Loss: " + std::to_string(loss) + "$");
}



