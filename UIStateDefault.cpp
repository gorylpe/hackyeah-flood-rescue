//
// Created by Piotr on 29.10.2017.
//

#include <iostream>
#include "UIStateDefault.h"
#include "UIManager.h"
#include "DrawingManager.h"
#include "ObjectManager.h"
#include "ObjectFirestation.h"
#include "ObjectFiretruck.h"
#include "ObjectHelicopter.h"
#include "UIStateFirestationDetails.h"
#include "UIStateFiretruckDetails.h"
#include "UIStateHelicopterDetails.h"


void UIStateDefault::draw(sf::RenderWindow *window) {

}

void UIStateDefault::handleClick(int x, int y) {
    UIElement *clicked = nullptr;
    for (int i = 0; i < elements->size(); i++) {
        if ((*elements)[i]->getRect().contains(x, y)) {
            clicked = (*elements)[i];
            break;
        }
    }

    if (clicked != nullptr) {
        clicked->onClick();
    } else {
        auto *drawingManager = &DrawingManager::getSingleton();
        int _x = drawingManager->getViewportTileX(x);
        int _y = drawingManager->getViewportTileY(y);
        Object *object = ObjectManager::getSingleton().getObjectAt(_x, _y);
        std::cout << "Clicked on " << _x << " - " << _y << std::endl;
        if (object != nullptr) {
            ObjectFirestation* objectFirestation = dynamic_cast<ObjectFirestation*>(object);
            ObjectFiretruck* objectFiretruck = dynamic_cast<ObjectFiretruck*>(object);
            ObjectHelicopter* objectHelicopter = dynamic_cast<ObjectHelicopter*>(object);
            if(objectFirestation != nullptr){
                UIStateFirestationDetails* newState = new UIStateFirestationDetails(objectFirestation);
                UIManager::getSingleton().changeState(newState);
            } else if(objectFiretruck != nullptr){
                UIStateFiretruckDetails* newState = new UIStateFiretruckDetails(objectFiretruck);
                UIManager::getSingleton().changeState(newState);
            } else if(objectHelicopter != nullptr){
                UIStateHelicopterDetails* newState = new UIStateHelicopterDetails(objectHelicopter);
                UIManager::getSingleton().changeState(newState);
            }
        }
    }
}

UIStateDefault::UIStateDefault() {
    std::cout << "Switched to Default state" << std::endl;
    elements = new std::vector<UIElement*>();
}
