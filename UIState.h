//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATE_H
#define GRA_UISTATE_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "UIElement.h"

class UIState {
public:
    virtual void draw(sf::RenderWindow *window) = 0;
    virtual void handleClick(int x, int y) = 0;
};


#endif //GRA_UISTATE_H
