//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECT_H
#define GRA_OBJECT_H

#include <string>


class Object {
    std::string name;
    int x, y;
public:
    Object(int _x, int _y)
    :x(_x)
    ,y(_y){}

    std::string getName(){return name;}

};


#endif //GRA_OBJECT_H
