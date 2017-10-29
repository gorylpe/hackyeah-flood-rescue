//
// Created by Piotr on 28.10.2017.
//

#include "ObjectFirestation.h"

ObjectFirestation::ObjectFirestation(int numberOfFiretrucks, int numberOfHelicopters, int _x, int _y)
:Object(OBJECTTYPE::FIRESTATION, DrawableObject::TEXTURE::FIRESTATION, _x, _y, 100000){
    trucks = new std::vector<ObjectFiretruck*>();
    helis = new std::vector<ObjectHelicopter*>();
    for(int i = 0; i < numberOfFiretrucks; ++i){
        trucks->push_back(new ObjectFiretruck(_x, _y));
    }
    for(int i = 0; i < numberOfHelicopters; ++i){
        helis->push_back(new ObjectHelicopter(_x, _y));
    }
}

void ObjectFirestation::update(Map *map) {
    for(ObjectFiretruck* objectFiretruck : *trucks){
        if(objectFiretruck->getPath() != nullptr){
            objectFiretruck->update(map);
        }
    }
    for(ObjectHelicopter* objectHelicopter : *helis){
        if(objectHelicopter->getPath() != nullptr){
            objectHelicopter->update(map);
        }
    }
}

int ObjectFirestation::getFreeFiretrucks() {
    int count = 0;
    for(ObjectFiretruck* objectFiretruck : *trucks){
        if(objectFiretruck->isFree()){
            ++count;
        }
    }
    return count;
}

int ObjectFirestation::getFreeHelicopters(){
    int count = 0;
    for(ObjectHelicopter* objectHelicopter : *helis){
        if(objectHelicopter->isFree()){
            ++count;
        }
    }
    return count;
}

ObjectFiretruck *ObjectFirestation::getFreeTruck() {
    for(ObjectFiretruck* objectFiretruck : *trucks){
        if(objectFiretruck->isFree()){
            return objectFiretruck;
        }
    }
    return nullptr;
}
ObjectHelicopter *ObjectFirestation::getFreeHelicopter() {
    for(ObjectHelicopter* objectHelicopter : *helis){
        if(objectHelicopter->isFree()){
            return objectHelicopter;
        }
    }
    return nullptr;
}
