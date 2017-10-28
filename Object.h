//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECT_H
#define GRA_OBJECT_H

#include <string>
#include "Map.h"


class Object {
    std::string name;
    int x, y;
public:
    Object(std::string _name, int _x, int _y)
    :name(_name)
    ,x(_x)
    ,y(_y){}

    std::string getName(){return name;}
    virtual void update(Map* map);
    int getX() { return x; }
    void setX(int x) { this->x = x; }
    int getY() { return y; }
    void setY(int y) { this->y = y; }

};


#endif //GRA_OBJECT_H
