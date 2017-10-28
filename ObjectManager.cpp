//
// Created by CLion on 28.10.2017.
//

#include "ObjectManager.h"

ObjectManager::ObjectManager() {
    objects = new std::vector<Object*>;
}

std::vector<Object *> *ObjectManager::getObjects() {
    return objects;
}

ObjectManager &ObjectManager::getSingleton() {
    static ObjectManager singleton;
    return singleton;
}

