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
    std::vector<ObjectFirestation*> *firestations;

public:
    static ObjectManager& getSingleton();
    std::vector<ObjectFirestation*> *getFirestations();
    ObjectFirestation *getObjectAt(int x, int y);

    void resetObjects();
};


#endif //GRA_OBJECTMANAGER_H
