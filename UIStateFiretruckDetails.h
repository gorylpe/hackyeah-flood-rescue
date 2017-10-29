//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEFIRETRUCKDETAILS_H
#define GRA_UISTATEFIRETRUCKDETAILS_H


#include "ObjectFirestation.h"
#include "UIState.h"
#include "UITextLabel.h"

class UIStateFiretruckDetails : public UIState{
    ObjectFiretruck *objectFiretruck;

    UITextLabel* buttonSandbagsLeft;
    UITextLabel* buttonSandbagsRight;
    UITextLabel* buttonSandbagsUp;
    UITextLabel* buttonSandbagsDown;

    UITextLabel* buttonReturnToBase;
    UITextLabel* buttonMove;

    UITextLabel* textSandbags;
public:
    explicit UIStateFiretruckDetails(ObjectFiretruck *_objectFiretruck);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;

    void drawButton(sf::RenderWindow *window, UITextLabel *button, int plusx, int plusy);

};


#endif //GRA_UISTATEFIRETRUCKDETAILS_H
