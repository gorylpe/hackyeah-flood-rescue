//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECTLOADER_H
#define GRA_OBJECTLOADER_H


#include <vector>
#include "Object.h"
#include "ObjectFirestation.h"

class ObjectLoader {
public:
    static std::vector<ObjectFirestation*>* loadObjects(std::string filename);
};


#endif //GRA_OBJECTLOADER_H
