//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEHELICOPTERDETAILS_H
#define GRA_UISTATEHELICOPTERDETAILS_H


#include "ObjectHelicopter.h"
#include "UIState.h"
#include "UITextLabel.h"

class UIStateHelicopterDetails : public UIState {
    ObjectHelicopter* objectHelicopter;

    UITextLabel* buttonSandbagsLeft;
    UITextLabel* buttonSandbagsRight;
    UITextLabel* buttonSandbagsUp;
    UITextLabel* buttonSandbagsDown;

    UITextLabel* buttonReturnToBase;
    UITextLabel* buttonMove;

    UITextLabel* textSandbags;
public:
    explicit UIStateHelicopterDetails(ObjectHelicopter *_objectHelicopter);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;

    void drawButton(UITextLabel *button, int plusx, int plusy);

    void drawButton(sf::RenderWindow *window, UITextLabel *button, int plusx, int plusy);
};


#endif //GRA_UISTATEHELICOPTERDETAILS_H
