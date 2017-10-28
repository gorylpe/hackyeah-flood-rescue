//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_OBJECTMANAGER_H
#define GRA_OBJECTMANAGER_H
#include <vector>
#include "Object.h"
#include "DrawingManager.h"
#include "ObjectLoader.h"


class ObjectManager {
    ObjectManager();
    ObjectManager(const ObjectManager&);
    std::vector<Object*> *objects;

public:
    static ObjectManager& getSingleton();
    std::vector<Object*> *getObjects();
    Object *getObjectAt(int x, int y);
};


#endif //GRA_OBJECTMANAGER_H
