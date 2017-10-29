//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEFIRETRUCKDETAILS_H
#define GRA_UISTATEFIRETRUCKDETAILS_H


#include "ObjectFirestation.h"
#include "UIState.h"

class UIStateFiretruckDetails : public UIState{

public:
    explicit UIStateFiretruckDetails(ObjectFiretruck *_objectFiretruck);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;
};


#endif //GRA_UISTATEFIRETRUCKDETAILS_H
