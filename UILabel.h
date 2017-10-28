//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_UILABEL_H
#define GRA_UILABEL_H


#include "UIElement.h"
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>

class UILabel : public UIElement {
    std::string value;
    sf::Text *text;
    int margin;
    sf::RectangleShape *frame;

public:
    UILabel(int _x, int _y);
    std::string getValue();
    void setValue(std::string value);
    void setFont(sf::Font *font);
    void setColor(sf::Color color);
    void setMargin(int margin);
    void setFrameColor(sf::Color color);
    int getHeight();
    int getWidth();

    void draw(sf::RenderWindow *window);
};


#endif //GRA_UILABEL_H
