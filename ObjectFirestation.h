//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECTFIRESTATION_H
#define GRA_OBJECTFIRESTATION_H


#include "Object.h"

class ObjectFirestation : public Object{
public:
    ObjectFirestation(int _x, int _y);

    void update(Map* map) override;
};


#endif //GRA_OBJECTFIRESTATION_H
