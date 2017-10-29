//
// Created by Piotr on 29.10.2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "UIStateFirestationDetails.h"
#include "UIManager.h"
#include "UIStateSendFiretruck.h"
#include "DrawingManager.h"
#include "UIStateDefault.h"

UIStateFirestationDetails::UIStateFirestationDetails(ObjectFirestation* _objectFirestation)
:objectFirestation(_objectFirestation){
    buttonTruck = new UITextLabel(0, 0, 40, 40, "Truck");
    buttonHeli = new UITextLabel(0, 0, 40, 40, "Choppa");
}

void UIStateFirestationDetails::draw(sf::RenderWindow *window) {
    const int width = (int)(DrawingManager::getSingleton().getTileWidth() * 2.5);
    const int height = (int)(DrawingManager::getSingleton().getTileWidth() * 1.25);
    int x = (objectFirestation->getX() - DrawingManager::getSingleton().getViewportX() - 1) * DrawingManager::getSingleton().getTileWidth();
    int y = (objectFirestation->getY() - DrawingManager::getSingleton().getViewportY() - 1) * DrawingManager::getSingleton().getTileHeight();

    sf::RectangleShape rect;
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(width, height));
    rect.setFillColor(sf::Color::Blue);

    window->draw(rect);

    buttonTruck->setX(x+DrawingManager::getSingleton().getTileWidth() / 10);
    buttonTruck->setY(y+DrawingManager::getSingleton().getTileHeight() / 10);
    buttonTruck->setWidth(DrawingManager::getSingleton().getTileWidth());
    buttonTruck->setHeight(DrawingManager::getSingleton().getTileHeight());
    buttonTruck->setFontSize(DrawingManager::getSingleton().getTileWidth() / 4);
    buttonTruck->setText(std::string("Truck(") + std::to_string(objectFirestation->getFreeFiretrucks()) + ")");
    buttonTruck->draw(window);
    buttonHeli->setX(x+DrawingManager::getSingleton().getTileWidth() / 10 + width / 2);
    buttonHeli->setY(y+DrawingManager::getSingleton().getTileHeight() / 10);
    buttonHeli->setWidth(DrawingManager::getSingleton().getTileWidth());
    buttonHeli->setHeight(DrawingManager::getSingleton().getTileHeight());
    buttonHeli->setFontSize(DrawingManager::getSingleton().getTileWidth() / 4);
    buttonHeli->setText(std::string("Heli(") + std::to_string(objectFirestation->getFreeHelicopters()) + ")");
    buttonHeli->draw(window);
}

void UIStateFirestationDetails::handleClick(int x, int y) {
    if(buttonTruck->getRect().contains(x, y) && objectFirestation->getFreeFiretrucks() > 0){
        ObjectFiretruck* truck = objectFirestation->getFreeTruck();
        UIManager::getSingleton().changeState(new UIStateSendFiretruck(truck));
    } else if(buttonHeli->getRect().contains(x, y) && objectFirestation->getFreeHelicopters() > 0){

    } else{
        UIManager::getSingleton().changeState(new UIStateDefault());
    }
}
