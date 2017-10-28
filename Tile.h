//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_TILE_H
#define GRA_TILE_H

#include "DrawableObject.h"

class Tile : public DrawableObject{
    int height;

    bool sandbagsUp;
    bool sandbagsDown;
    bool sandbagsLeft;
    bool sandbagsRight;

public:
    Tile();

    int         getHeight(){return height;}

    void        setHeight(int newHeight){ height = newHeight; }

    void        setSandbagsUp(bool set){sandbagsUp = set;}
    void        setSandbagsDown(bool set){sandbagsDown = set;}
    void        setSandbagsLeft(bool set){sandbagsLeft = set;}
    void        setSandbagsRight(bool set){sandbagsRight = set;}

    bool        getSandbagsUp(){ return sandbagsUp;}
    bool        getSandbagsDown(){ return sandbagsDown;}
    bool        getSandbagsLeft(){ return sandbagsLeft;}
    bool        getSandbagsRight(){ return sandbagsRight;}
};

#endif