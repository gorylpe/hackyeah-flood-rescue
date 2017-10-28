//
// Created by CLion on 28.10.2017.
//

#include <SFML/Graphics/Text.hpp>
#include "UILabel.h"

UILabel::UILabel(int _x, int _y, int _width, int _height):
        UIElement(_x, _y, _width, _height) {

}

std::string UILabel::getValue() {
    return value;
}

void UILabel::setValue(std::string value) {
    this->value = value;
}

void UILabel::draw(sf::RenderWindow *window) {
    sf::Text text;
    text.setFont(*font);
    text.setFillColor(color);
    text.setString(value);
    text.setPosition(x, y);
    window->draw(text);
}

void UILabel::setFont(sf::Font *font) {
    this->font = font;
}

void UILabel::setColor(sf::Color color) {
    this->color = color;
}
