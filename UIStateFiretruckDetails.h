//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEFIRETRUCKDETAILS_H
#define GRA_UISTATEFIRETRUCKDETAILS_H


#include "ObjectFirestation.h"
#include "UIState.h"
#include "UIButton.h"

class UIStateFiretruckDetails : public UIState{
    ObjectFiretruck *objectFiretruck;

    UIButton* buttonSandbagsLeft;
    UIButton* buttonSandbagsRight;
    UIButton* buttonSandbagsUp;
    UIButton* buttonSandbagsDown;

    UIButton* buttonReturnToBase;
    UIButton* buttonMove;
public:
    explicit UIStateFiretruckDetails(ObjectFiretruck *_objectFiretruck);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;

    void drawButton(UIButton *button, int plusx, int plusy);

    void drawButton(sf::RenderWindow *window, UIButton *button, int plusx, int plusy);
};


#endif //GRA_UISTATEFIRETRUCKDETAILS_H
