//
// Created by CLion on 28.10.2017.
//

#include "ObjectManager.h"
#include "ObjectLoader.h"

ObjectManager::ObjectManager() {
    objects = ObjectLoader::loadObjects("objects1.txt");
}

std::vector<Object *> *ObjectManager::getObjects() {
    return objects;
}

ObjectManager &ObjectManager::getSingleton() {
    static ObjectManager singleton;
    return singleton;
}

Object *ObjectManager::getObjectAt(int x, int y) {
    for (int i = 0; i < objects->size(); i++) {
        if ((*objects)[i]->getX() == x && (*objects)[i]->getY() == y) {
           return (*objects)[i];
        }
    }
    return nullptr;
}

void ObjectManager::resetObjects() {
    for (int i = 0; i < objects->size(); i++) {
         delete objects[i];
    }
    delete objects;
    objects = ObjectLoader::loadObjects("objects1.txt");
}

