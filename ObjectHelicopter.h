//
// Created by pietrk01 on 10/28/2017.
//

#ifndef GRA_OBJECTHELICOPTER_H
#define GRA_OBJECTHELICOPTER_H

#include <SFML/System.hpp>
#include <vector>
#include "Object.h"

class ObjectFirestation;

class ObjectHelicopter : public Object {
    std::vector<sf::Vector2i>* path;
    int currentPositionInPath;

    bool free;

    int numberOfSandbags;

    ObjectFirestation* base;
    bool goToBase = false;
public:
    ObjectHelicopter(int _x, int _y, ObjectFirestation* _base);
    void update(Map* map) override;

    bool newPathTo(Map *map, int x, int y);
    bool newPathToBase(Map *map, int x, int y);

    std::vector<sf::Vector2i>* getPath(){return path;}

    void setFree(bool _free){free = _free;};
    bool isFree(){return free;};

    int getNumberOfSandbags();

    void setNumberOfSandbags(int i);

    ObjectFirestation* getBase();
};


#endif //GRA_OBJECTHELICOPTER_H
