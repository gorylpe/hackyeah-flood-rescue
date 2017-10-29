//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_OBJECTFIRESTATION_H
#define GRA_OBJECTFIRESTATION_H


#include "Object.h"
#include "ObjectFiretruck.h"
#include "ObjectHelicopter.h"

class ObjectFirestation : public Object{
    std::vector<ObjectFiretruck*>* trucks;
    std::vector<ObjectHelicopter *> *helis;
public:
    ObjectFirestation(int numberOfFiretrucks, int numberOfHelicopters, int _x, int _y);

    void update(Map* map) override;

    int getFreeFiretrucks();
    int getFreeHelicopters();

    ObjectFiretruck *getFreeTruck();
    ObjectHelicopter *getFreeHelicopter();

    std::vector<ObjectFiretruck*>* getFiretrucks(){ return trucks;};
    std::vector<ObjectHelicopter*>* getHelicopters() { return helis;};
};


#endif //GRA_OBJECTFIRESTATION_H
