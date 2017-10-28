//
// Created by Piotr on 28.10.2017.
//

#include <fstream>
#include "ObjectLoader.h"

std::vector<Object*>* ObjectLoader::loadObjects(std::string filename) {
    std::ifstream file;
    file.open(filename);
    int numberOfObjects;
    file >> numberOfObjects;
    auto* objects = new std::vector<Object*>();

    int type;
    int x, y;
    for(int i = 0; i < numberOfObjects; ++i){
        file >> type >> x >> y;
        auto objecttype = static_cast<Object::OBJECTTYPE>(type);
        Object* object = new Object(objecttype, x, y);
        objects->push_back(object);
    }

    return objects;
}
