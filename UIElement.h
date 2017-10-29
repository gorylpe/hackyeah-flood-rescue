//
// Created by pietrk01 on 10/28/2017.
//

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef GRA_UIELEMENT_H
#define GRA_UIELEMENT_H


class UIElement {
protected:
    int x, y, width, height;
    bool visible;

public:
    UIElement(int _x, int _y, int _width, int _height)
            :x(_x),
             y(_y),
             width(_width),
             height(_height),
             visible(true) {}

    int getX(){return x;}
    int getY(){return y;}
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getWidth(){return width;}
    int getHeight(){return height;}
    sf::IntRect getRect() { return sf::IntRect(x, y, width, height); }
    virtual void onClick() {};

    virtual void draw(sf::RenderWindow *window) = 0;
    void setVisible(bool visible);
};


#endif //GRA_UIELEMENT_H
