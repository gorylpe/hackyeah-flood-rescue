//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEDEFAULT_H
#define GRA_UISTATEDEFAULT_H


#include "UIState.h"

class UIStateDefault : public UIState {
    std::vector<UIElement*> *elements;
public:
    UIStateDefault();
    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y);

};


#endif //GRA_UISTATEDEFAULT_H
