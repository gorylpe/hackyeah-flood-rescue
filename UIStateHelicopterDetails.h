//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEHELICOPTERDETAILS_H
#define GRA_UISTATEHELICOPTERDETAILS_H


#include "ObjectHelicopter.h"
#include "UIState.h"

class UIStateHelicopterDetails : public UIState {

public:
    explicit UIStateHelicopterDetails(ObjectHelicopter *_objectHelicopter);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;
};


#endif //GRA_UISTATEHELICOPTERDETAILS_H
