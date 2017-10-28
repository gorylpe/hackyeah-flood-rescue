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

public:
    UIElement(int _x, int _y, int _width, int _height)
            :x(_x),
             y(_y),
             width(_width),
             height(_height){}

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    virtual void draw(sf::RenderWindow *window);
};


#endif //GRA_UIELEMENT_H
