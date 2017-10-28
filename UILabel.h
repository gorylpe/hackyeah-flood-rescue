//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_UILABEL_H
#define GRA_UILABEL_H


#include "UIElement.h"
#include <string>

class UILabel : public UIElement {
    std::string value;
    sf::Font *font;
    sf::Color color;

public:
    UILabel(int _x, int _y, int _width, int _height);
    std::string getValue();
    void setValue(std::string value);
    void setFont(sf::Font *font);
    void setColor(sf::Color color);

    void draw(sf::RenderWindow *window);
};


#endif //GRA_UILABEL_H
