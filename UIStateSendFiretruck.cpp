//
// Created by Piotr on 29.10.2017.
//

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
    bool pathExits = objectFiretruck->newPathTo(GameManager::getSingleton().getMap(), DrawingManager::getSingleton().getViewportTileX(x), DrawingManager::getSingleton().getViewportTileY(y));
    if(pathExits){
        objectFiretruck->setFree(false);
    }
    UIManager::getSingleton().changeState(new UIStateDefault());
}
