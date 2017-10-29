//
// Created by Piotr on 28.10.2017.
//

#include <fstream>
#include "ObjectLoader.h"
#include "ObjectFirestation.h"
#include "ObjectFiretruck.h"
#include "ObjectHelicopter.h"

std::vector<ObjectFirestation*>* ObjectLoader::loadObjects(std::string filename) {
    std::ifstream file;
    file.open(filename);
    int numberOfObjects;
    file >> numberOfObjects;
    auto* objects = new std::vector<ObjectFirestation*>();

    int type;
    int x, y;
    for(int i = 0; i < numberOfObjects; ++i){
        file >> type >> x >> y;
        auto objecttype = static_cast<ObjectFirestation::OBJECTTYPE>(type);
        ObjectFirestation* object;
        switch(objecttype){
            case ObjectFirestation::OBJECTTYPE::FIRESTATION:
                object = new ObjectFirestation(5, 1, x, y);
                break;
        }
        objects->push_back(object);
    }

    return objects;
}
