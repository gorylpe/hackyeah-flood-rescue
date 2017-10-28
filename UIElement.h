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
public:
    int getX(){return x;}
    int getY(){return y;}
    int getWidth(){return width;}
    int getHeight(){return height;}

    virtual void draw(sf::RenderWindow *window) = 0;
};


#endif //GRA_UIELEMENT_H
