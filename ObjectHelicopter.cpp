//
// Created by pietrk01 on 10/28/2017.
//

#include "ObjectHelicopter.h"

ObjectHelicopter::ObjectHelicopter(int _x, int _y)
:Object(OBJECTTYPE::HELICOPTER, DrawableObject::TEXTURE::HELI, _x, _y)
,free(true){}
