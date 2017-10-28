//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECT_H
#define GRA_OBJECT_H

#include <string>
#include "Map.h"


class Object : public DrawableObject{
public:
    enum OBJECTTYPE{
        FIRESTATION = 0,
        FIRETRUCK = 1,
        HELICOPTER = 2
    };
protected:
    std::string name;
    int x, y;
    OBJECTTYPE objectType;
public:
    Object(OBJECTTYPE _objectType, DrawableObject::TEXTURE _texture, int _x, int _y)
    :objectType(_objectType)
    ,x(_x)
    ,y(_y){
        setTexture(_texture);
    }

    std::string getName(){return name;}
    virtual void update(Map* map) = 0;
    int getX() { return x; }
    void setX(int x) { this->x = x; }
    int getY() { return y; }
    void setY(int y) { this->y = y; }
    void setObjectType(OBJECTTYPE _objectType){objectType = _objectType;}
    OBJECTTYPE getObjectType(){return objectType;}

};


#endif //GRA_OBJECT_H
