//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECTFIRETRUCK_H
#define GRA_OBJECTFIRETRUCK_H

#include <SFML/System.hpp>
#include <vector>
#include "Object.h"

class ObjectFiretruck : public Object {
    std::vector<sf::Vector2i>* path;
    int currentPositionInPath;
public:
    ObjectFiretruck(int _x, int _y);
    //TODO list of points to move
    void update(Map* map) override;

    bool newPathTo(Map *map, int x, int y);

    std::vector<sf::Vector2i>* getPath(){return path;}
};


#endif //GRA_OBJECTFIRETRUCK_H
