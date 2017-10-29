//
// Created by CLion on 28.10.2017.
//

#include "ObjectManager.h"
#include "ObjectLoader.h"
#include "ObjectFiretruck.h"

ObjectManager::ObjectManager() {
    firestations = ObjectLoader::loadObjects("objects1.txt");
}

std::vector<ObjectFirestation *> *ObjectManager::getFirestations() {
    return firestations;
}

ObjectManager &ObjectManager::getSingleton() {
    static ObjectManager singleton;
    return singleton;
}

ObjectFirestation *ObjectManager::getObjectAt(int x, int y) {
    for (int i = 0; i < firestations->size(); i++) {
        if ((*firestations)[i]->getX() == x && (*firestations)[i]->getY() == y) {
           return (*firestations)[i];
        }
    }
    return nullptr;
}

void ObjectManager::resetObjects() {
    firestations->erase(firestations->begin(), firestations->end());
    delete firestations;
    firestations = ObjectLoader::loadObjects("objects1.txt");
}

