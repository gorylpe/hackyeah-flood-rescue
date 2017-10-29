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
    int newx = DrawingManager::getSingleton().getViewportTileX(x);
    int newy = DrawingManager::getSingleton().getViewportTileY(y);
    if(newx != objectHelicopter->getX() || newy != objectHelicopter->getY()){
        bool pathExits = objectHelicopter->newPathTo(GameManager::getSingleton().getMap(), newx, newy);
        if(pathExits){
            objectHelicopter->setFree(false);
        }
    } else {
        std::cout << "moving to same place" << std::endl;
    }
    UIManager::getSingleton().changeState(new UIStateDefault());
}
