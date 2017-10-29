//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATESENDFIRETRUCK_H
#define GRA_UISTATESENDFIRETRUCK_H


#include "UIState.h"
#include "ObjectFiretruck.h"

class UIStateSendFiretruck : public UIState {
    ObjectFiretruck* objectFiretruck;
public:
    explicit UIStateSendFiretruck(ObjectFiretruck* objectFiretruck);
    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;
};


#endif //GRA_UISTATESENDFIRETRUCK_H
