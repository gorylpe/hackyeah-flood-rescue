//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UIBUTTON_H
#define GRA_UIBUTTON_H


#include "UIElement.h"

class UIButton : public UIElement{
    std::string text;
    int fontSize;
public:
    UIButton(int _x, int _y, int _width, int _height, std::string text);

    void draw(sf::RenderWindow *window);
    void setFontSize(int size) { fontSize = size; }
    void setText(std::string text) { this->text = text; }
};


#endif //GRA_UIBUTTON_H
