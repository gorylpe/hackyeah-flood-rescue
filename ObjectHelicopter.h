//
// Created by pietrk01 on 10/28/2017.
//

#ifndef GRA_OBJECTHELICOPTER_H
#define GRA_OBJECTHELICOPTER_H

#include <SFML/System.hpp>
#include <vector>
#include "Object.h"


class ObjectHelicopter : public Object {
    std::vector<sf::Vector2i>* path;
    int currentPositionInPath;

    bool free;

    int numberOfSandbags;
public:
    ObjectHelicopter(int _x, int _y);
    void update(Map* map) override;

    bool newPathTo(Map *map, int x, int y);

    std::vector<sf::Vector2i>* getPath(){return path;}

    void setFree(bool _free){free = _free;};
    bool isFree(){return free;};

    int getNumberOfSandbags();

    void setNumberOfSandbags(int i);
};


#endif //GRA_OBJECTHELICOPTER_H
