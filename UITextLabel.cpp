//
// Created by Piotr on 29.10.2017.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "UITextLabel.h"
#include "DrawingManager.h"

UITextLabel::UITextLabel(int _x, int _y, int _width, int _height, std::string _text)
:UIElement(_x, _y, _width, _height),
text(_text),
 fontSize(20)
{}

void UITextLabel::draw(sf::RenderWindow *window) {
    sf::RectangleShape rect;
    rect.setPosition(getX(), getY());
    rect.setFillColor(sf::Color::Yellow);
    rect.setSize(sf::Vector2f(getWidth(), getHeight()));
    sf::Text text;
    text.setFont(*DrawingManager::getSingleton().getFont());
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::Black);
    text.setString(this->text);
    text.setPosition(getX(), getY());

    window->draw(rect);
    window->draw(text);
}
