//
// Created by pietrk01 on 10/28/2017.
//

#include <iostream>
#include "ObjectHelicopter.h"

ObjectHelicopter::ObjectHelicopter(int _x, int _y, ObjectFirestation* _base)
:Object(OBJECTTYPE::HELICOPTER, DrawableObject::TEXTURE::HELI, _x, _y, 20000)
,base(_base)
,free(true)
,path(nullptr)
,currentPositionInPath(0)
,numberOfSandbags(10){}

void ObjectHelicopter::update(Map *map) {
    if(path != nullptr){
        int x = path->at(currentPositionInPath).x;
        int y = path->at(currentPositionInPath).y;
        setX(x);
        setY(y);
        ++currentPositionInPath;
        if(currentPositionInPath == path->size()){
            delete path;
            path = nullptr;
            if(goToBase){
                setFree(true);
                setNumberOfSandbags(10);
            }
        }
    }
}


bool ObjectHelicopter::newPathTo(Map *map, int x, int y) {
    goToBase = false;
    if(path != nullptr){
        delete path;
        path = nullptr;
    }

    currentPositionInPath = 0;

    sf::Vector2i s;
    s.x = getX();
    s.y = getY();

    path = new std::vector<sf::Vector2i>();

    while(s.x != x || s.y != y){
        int moves = 0;
        if(s.x < x){
            s.x += 1;
            ++moves;
        } else if(s.x > x){
            s.x -= 1;
            ++moves;
        }
        if(s.y < y){
            if(s.y < y - 1)
                s.y += 2 - moves;
            else
                s.y += 1;
        } else if(s.y > y){
            if(s.y > y + 1)
                s.y -= 2 - moves;
            else
                s.y -= 1;
        }

        path->push_back(sf::Vector2i(s.x,s.y));
    }

    return true;
}


bool ObjectHelicopter::newPathToBase(Map *map, int x, int y) {
    goToBase = true;
    if(path != nullptr){
        delete path;
        path = nullptr;
    }

    currentPositionInPath = 0;

    sf::Vector2i s;
    s.x = getX();
    s.y = getY();

    path = new std::vector<sf::Vector2i>();

    while(s.x != x || s.y != y){
        int moves = 0;
        if(s.x < x){
            s.x += 1;
            ++moves;
        } else if(s.x > x){
            s.x -= 1;
            ++moves;
        }
        if(s.y < y){
            if(s.y < y - 1)
                s.y += 2 - moves;
            else
                s.y += 1;
        } else if(s.y > y){
            if(s.y > y + 1)
                s.y -= 2 - moves;
            else
                s.y -= 1;
        }

        path->push_back(sf::Vector2i(s.x,s.y));
    }

    return true;
}

int ObjectHelicopter::getNumberOfSandbags() {
    return numberOfSandbags;
}

void ObjectHelicopter::setNumberOfSandbags(int i) {
    numberOfSandbags = i;
}

ObjectFirestation *ObjectHelicopter::getBase() {
    return base;
}