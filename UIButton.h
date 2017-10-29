//
// Created by pietrk01 on 10/29/2017.
//

#ifndef GRA_UIBUTTON_H
#define GRA_UIBUTTON_H

#include "UIElement.h"

class UIButton : public UIElement {
    sf::Color color;
    void (*clickCallback)();

public:
    UIButton(int _x, int _y, int _width, int _height);
    void isPressed();
    void draw(sf::RenderWindow *window);
    void setColor(sf::Color color) { this->color = color; }
    void setOnClick(void (*onClick)()) { clickCallback = onClick; }
    void onClick();
};


#endif //GRA_UIBUTTON_H
