//
// Created by pietrk01 on 10/29/2017.
//

#ifndef GRA_UIBUTTON_H
#define GRA_UIBUTTON_H

#include "UIElement.h"

class UIButton : public UIElement {
public:
    UIButton(int _x, int _y, int _width, int _height);
    void isPressed();

};


#endif //GRA_UIBUTTON_H
