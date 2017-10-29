//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATEFIRESTATIONDETAILS_H
#define GRA_UISTATEFIRESTATIONDETAILS_H


#include "ObjectFirestation.h"
#include "UIState.h"
#include "UITextLabel.h"

class UIStateFirestationDetails : public UIState {
    ObjectFirestation* objectFirestation;

    UITextLabel* buttonTruck;
    UITextLabel* buttonHeli;
public:
    explicit UIStateFirestationDetails(ObjectFirestation *_objectFirestation);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;

};


#endif //GRA_UISTATEFIRESTATIONDETAILS_H
