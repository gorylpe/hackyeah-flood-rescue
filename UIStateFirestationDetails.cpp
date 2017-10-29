//
// Created by Piotr on 29.10.2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "UIStateFirestationDetails.h"
#include "UIManager.h"
#include "UIStateSendFiretruck.h"
#include "DrawingManager.h"

UIStateFirestationDetails::UIStateFirestationDetails(ObjectFirestation* _objectFirestation)
:objectFirestation(_objectFirestation){
    buttonTruck = new UIButton(0, 0, 40, 40, "Truck");
    buttonHeli = new UIButton(0, 0, 40, 40, "Choppa");
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

    buttonTruck->setText(std::string("Truck(") + std::to_string(objectFirestation->getFreeFiretrucks()) + ")");
    buttonTruck->setX(x+5);
    buttonTruck->setY(y+5);
    buttonTruck->draw(window);

    buttonHeli->setText(std::string("Heli(") + std::to_string(objectFirestation->getFreeHelicopters()) + ")");
    buttonHeli->setX(x+55);
    buttonHeli->setY(y+5);
    buttonHeli->draw(window);
}

void UIStateFirestationDetails::handleClick(int x, int y) {
    if(buttonTruck->getRect().contains(x, y)){
        if(objectFirestation->getFreeFiretrucks() > 0){
            ObjectFiretruck* truck = objectFirestation->getFreeTruck();
            UIManager::getSingleton().changeState(new UIStateSendFiretruck(truck));
        }
    }
}
