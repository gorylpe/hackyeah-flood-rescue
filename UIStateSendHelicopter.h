//
// Created by Piotr on 29.10.2017.
//

#ifndef GRA_UISTATESENDHELICOPTER_H
#define GRA_UISTATESENDHELICOPTER_H


#include "UIState.h"
#include "ObjectHelicopter.h"

class UIStateSendHelicopter : public UIState {
    ObjectHelicopter* objectHelicopter;
public:
    explicit UIStateSendHelicopter(ObjectHelicopter *_objectHelicopter);

    void draw(sf::RenderWindow *window) override;

    void handleClick(int x, int y) override;
};


#endif //GRA_UISTATESENDHELICOPTER_H
