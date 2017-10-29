//
// Created by pietrk01 on 10/28/2017.
//

#ifndef GRA_OBJECTHELICOPTER_H
#define GRA_OBJECTHELICOPTER_H

#include "Object.h"


class ObjectHelicopter : public Object {

    bool free;
public:
    ObjectHelicopter(int _x, int _y);

    virtual void update(Map* map){};

    void setFree(bool _free){free = _free;};
    bool isFree(){return free;};
};


#endif //GRA_OBJECTHELICOPTER_H
