//
// Created by pietrk01 on 10/29/2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "UIButton.h"

UIButton::UIButton(int _x, int _y, int _width, int _height):
        UIElement(_x, _y, _width, _height) {

}

void UIButton::isPressed() {

}

void UIButton::draw(sf::RenderWindow *window) {
    sf::RectangleShape rect;
    sf::Vector2f size(width, height);
    rect.setSize(size);
    rect.setPosition(x, y);
    rect.setFillColor(color);
    window->draw(rect);
}

void UIButton::onClick() {
    clickCallback();
}
