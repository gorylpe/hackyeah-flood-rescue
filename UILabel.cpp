//
// Created by CLion on 28.10.2017.
//

#include <SFML/Graphics/Text.hpp>
#include "UILabel.h"

UILabel::UILabel(int _x, int _y):
        UIElement(_x, _y, 0, 0) {
    this->text = new sf::Text();
    this->frame = new sf::RectangleShape;
}

std::string UILabel::getValue() {
    return value;
}

void UILabel::setValue(std::string value) {
    this->value = value;
    this->text->setString(value);
}

void UILabel::draw(sf::RenderWindow *window) {
    if (visible) {
        auto bounds = text->getLocalBounds();
        frame->setPosition(x, y);
        frame->setSize(sf::Vector2f(bounds.width + margin, bounds.height + margin));
        window->draw(*frame);
        text->setPosition(x + margin, y + margin);
        window->draw(*text);
    }
}

void UILabel::setFont(sf::Font *font) {
    this->text->setFont(*font);
}

void UILabel::setColor(sf::Color color) {
    this->text->setFillColor(color);
}

int UILabel::getHeight() {
    return this->text->getLocalBounds().height + margin;
}

int UILabel::getWidth() {
    return this->text->getLocalBounds().width + margin;
}

void UILabel::setMargin(int margin) {
    this->margin = margin;
}

void UILabel::setFrameColor(sf::Color color) {
    this->frame->setFillColor(color);
}
