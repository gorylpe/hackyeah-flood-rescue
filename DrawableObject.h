//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_DRAWABLEOBJECT_H
#define GRA_DRAWABLEOBJECT_H


class DrawableObject {
public:
    enum TEXTURE {
        WATER = 0,
        BUILDING = 1,
        GRASS = 2,
        FOREST = 3,
        ROAD = 4,
        SANDBAGS = 5
    };
private:
    TEXTURE texture;

public:

    TEXTURE     getTexture(){return texture;}
    void        setTexture(TEXTURE _texture){ texture = _texture; }
};


#endif //GRA_DRAWABLEOBJECT_H
