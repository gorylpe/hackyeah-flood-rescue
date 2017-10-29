//
// Created by Piotr on 29.10.2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "UIStateFiretruckDetails.h"
#include "DrawingManager.h"
#include "GameManager.h"
#include "UIManager.h"
#include "UIStateSendFiretruck.h"
#include "UIStateDefault.h"

UIStateFiretruckDetails::UIStateFiretruckDetails(ObjectFiretruck *_objectFiretruck)
:objectFiretruck(_objectFiretruck){
    buttonSandbagsDown = new UIButton(0, 0, 40, 40, "\\/");
    buttonSandbagsUp = new UIButton(0, 0, 40, 40, "^");
    buttonSandbagsLeft = new UIButton(0, 0, 40, 40, "<");
    buttonSandbagsRight = new UIButton(0, 0, 40, 40, ">");
    buttonReturnToBase = new UIButton(0, 0, 40, 40, "Return");
    buttonMove = new UIButton(0, 0, 40, 40, "Move");
}

void UIStateFiretruckDetails::draw(sf::RenderWindow *window) {
    const int tWidth = DrawingManager::getSingleton().getTileWidth();
    const int tHeight = DrawingManager::getSingleton().getTileHeight();
    const int width = (int)(tWidth * 5);
    const int height = (int)(tHeight * 2.5);
    int x = (objectFiretruck->getX() - DrawingManager::getSingleton().getViewportX() - 2) * tWidth;
    int y = (objectFiretruck->getY() - DrawingManager::getSingleton().getViewportY() - 2) * tHeight;

    sf::RectangleShape rect;
    rect.setPosition(x, y);
    rect.setSize(sf::Vector2f(width, height));
    rect.setFillColor(sf::Color::Blue);

    window->draw(rect);

    int xdelta = tWidth / 10;
    int ydelta = tHeight / 10;
    int fontsize = tWidth / 4;

    drawButton(window, buttonSandbagsDown, xdelta, 3*ydelta + tHeight);
    drawButton(window, buttonSandbagsUp, 3*xdelta + tWidth, 3*ydelta + tHeight);
    drawButton(window, buttonSandbagsLeft, 5*xdelta + 2*tWidth, 3*ydelta + tHeight);
    drawButton(window, buttonSandbagsRight, 7*xdelta + 3*tWidth, 3*ydelta + tHeight);
    drawButton(window, buttonReturnToBase, 3*xdelta + tWidth, ydelta);
    drawButton(window, buttonMove, 5*xdelta + 2*tWidth, ydelta);
}

void UIStateFiretruckDetails::drawButton(sf::RenderWindow *window, UIButton* button, int plusx, int plusy){
    const int tWidth = DrawingManager::getSingleton().getTileWidth();
    const int tHeight = DrawingManager::getSingleton().getTileHeight();
    const int width = (int)(tWidth * 5);
    const int height = (int)(tHeight * 2.5);
    int x = (objectFiretruck->getX() - DrawingManager::getSingleton().getViewportX() - 2) * tWidth;
    int y = (objectFiretruck->getY() - DrawingManager::getSingleton().getViewportY() - 2) * tHeight;

    int fontsize = tWidth / 4;

    button->setX(x+plusx);
    button->setY(y+plusy);
    button->setWidth(tWidth);
    button->setHeight(tHeight);
    button->setFontSize(fontsize);
    button->draw(window);
}

void UIStateFiretruckDetails::handleClick(int x, int y) {
    if(buttonSandbagsDown->getRect().contains(x, y)){
        if(!GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->getSandbagsDown()){
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsDown(true);
        } else {
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsDown(false);
        }
    } else if(buttonSandbagsUp->getRect().contains(x, y)) {
        if(!GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->getSandbagsUp()){
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsUp(true);
        } else {
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsUp(false);
        }
    } else if(buttonSandbagsLeft->getRect().contains(x, y)) {
        if(!GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->getSandbagsLeft()){
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsLeft(true);
        } else {
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsLeft(false);
        }
    } else if(buttonSandbagsRight->getRect().contains(x, y)) {
        if(!GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->getSandbagsRight()){
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsRight(true);
        } else {
            GameManager::getSingleton().getMap()->getTile(objectFiretruck->getX(), objectFiretruck->getY())->setSandbagsRight(false);
        }
    } else if(buttonReturnToBase->getRect().contains(x, y)) {
        //TODO
    } else if(buttonMove->getRect().contains(x, y)) {
        UIManager::getSingleton().changeState(new UIStateSendFiretruck(objectFiretruck));
    } else {
        UIManager::getSingleton().changeState(new UIStateDefault());
    }
}
