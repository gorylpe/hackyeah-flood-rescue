//
// Created by Piotr on 29.10.2017.
//

#include <iostream>
#include "UIStateSendHelicopter.h"
#include "UIStateDefault.h"
#include "UIManager.h"
#include "GameManager.h"

UIStateSendHelicopter::UIStateSendHelicopter(ObjectHelicopter *_objectHelicopter)
:objectHelicopter(_objectHelicopter){

}

void UIStateSendHelicopter::draw(sf::RenderWindow *window) {

}

void UIStateSendHelicopter::handleClick(int x, int y) {
    bool pathExits = objectHelicopter->newPathTo(GameManager::getSingleton().getMap(), DrawingManager::getSingleton().getViewportTileX(x), DrawingManager::getSingleton().getViewportTileY(y));
    if(pathExits){
        objectHelicopter->setFree(false);
    }
    UIManager::getSingleton().changeState(new UIStateDefault());
}
