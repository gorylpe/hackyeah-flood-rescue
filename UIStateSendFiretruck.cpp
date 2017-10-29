//
// Created by Piotr on 29.10.2017.
//

#include <iostream>
#include "UIStateSendFiretruck.h"
#include "GameManager.h"
#include "UIManager.h"
#include "UIStateDefault.h"

UIStateSendFiretruck::UIStateSendFiretruck(ObjectFiretruck *_objectFiretruck)
:objectFiretruck(_objectFiretruck){

}

void UIStateSendFiretruck::draw(sf::RenderWindow *window) {

}

void UIStateSendFiretruck::handleClick(int x, int y) {
    int newx = DrawingManager::getSingleton().getViewportTileX(x);
    int newy = DrawingManager::getSingleton().getViewportTileY(y);
    if(newx != objectFiretruck->getX() || newy != objectFiretruck->getY()) {
        bool pathExits = objectFiretruck->newPathTo(GameManager::getSingleton().getMap(), newx, newy);
        if (pathExits) {
            objectFiretruck->setFree(false);
        }
    } else {
        std::cout << "moving to same place" << std::endl;
    }
    UIManager::getSingleton().changeState(new UIStateDefault());
}
