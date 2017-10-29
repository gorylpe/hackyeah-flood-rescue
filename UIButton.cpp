//
// Created by Piotr on 29.10.2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "UIButton.h"

UIButton::UIButton(int _x, int _y, int _width, int _height)
:UIElement(_x, _y, _width, _height) {}

void UIButton::draw(sf::RenderWindow *window) {
    sf::RectangleShape rect;
    rect.setPosition(getX(), getY());
    rect.setFillColor(sf::Color::Yellow);
    rect.setSize(sf::Vector2f(getWidth(), getHeight()));

    window->draw(rect);
}
