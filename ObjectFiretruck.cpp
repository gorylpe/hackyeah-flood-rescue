//
// Created by Piotr on 28.10.2017.
//

#include <queue>
#include <iostream>
#include "ObjectFiretruck.h"

ObjectFiretruck::ObjectFiretruck(int _x, int _y)
:Object(OBJECTTYPE::FIRETRUCK, DrawableObject::TEXTURE::FIRETRUCK, _x, _y, 10000)
,free(true)
,path(nullptr)
,numberOfSandbags(5){}

void ObjectFiretruck::update(Map *map) {
    if(path != nullptr){
        int x = path->at(currentPositionInPath).x;
        int y = path->at(currentPositionInPath).y;
        setX(x);
        setY(y);
        ++currentPositionInPath;
        if(currentPositionInPath == path->size()){
            delete path;
            path = nullptr;
        }
    }
}

bool ObjectFiretruck::newPathTo(Map *map, int x, int y){
    currentPositionInPath = 0;

    int** dist = new int*[map->getWidth()];
    for (int i = 0; i < map->getWidth(); i++) {
        dist[i] = new int[map->getHeight()];
        for (int j = 0; j < map->getHeight(); ++j) {
            dist[i][j] = -1;
        }
    }
    sf::Vector2i s;
    s.x = getX();
    s.y = getY();
    dist[s.x][s.y] = 0;

    std::queue<sf::Vector2i> q;
    q.push(s);
    while(!q.empty()){
        sf::Vector2i u;
        u = q.front();
        q.pop();

        if(u.x == x && u.y == y)
            break;

        sf::Vector2i v1;
        v1.x = u.x - 1;
        v1.y = u.y;
        if(v1.x >= 0 && dist[v1.x][v1.y] == -1 &&
                (map->getTile(v1.x, v1.y)->getTexture() == DrawableObject::TEXTURE::ROAD || map->getTile(v1.x, v1.y)->getTexture() == DrawableObject::TEXTURE::GRASS)){
            dist[v1.x][v1.y] = dist[u.x][u.y] + 1;
            q.push(v1);
        }
        sf::Vector2i v2;
        v2.x = u.x + 1;
        v2.y = u.y;
        if(v2.x < map->getWidth() && dist[v2.x][v2.y] == -1 &&
                (map->getTile(v2.x, v2.y)->getTexture() == DrawableObject::TEXTURE::ROAD || map->getTile(v2.x, v2.y)->getTexture() == DrawableObject::TEXTURE::GRASS)){
            dist[v2.x][v2.y] = dist[u.x][u.y] + 1;
            q.push(v2);
        }
        sf::Vector2i v3;
        v3.x = u.x;
        v3.y = u.y - 1;
        if(v3.y >= 0 && dist[v3.x][v3.y] == -1 &&
                (map->getTile(v3.x, v3.y)->getTexture() == DrawableObject::TEXTURE::ROAD || map->getTile(v3.x, v3.y)->getTexture() == DrawableObject::TEXTURE::GRASS)){
            dist[v3.x][v3.y] = dist[u.x][u.y] + 1;
            q.push(v3);
        }
        sf::Vector2i v4;
        v4.x = u.x;
        v4.y = u.y + 1;
        if(v4.y < map->getHeight() && dist[v4.x][v4.y] == -1 &&
           (map->getTile(v4.x, v4.y)->getTexture() == DrawableObject::TEXTURE::ROAD || map->getTile(v4.x, v4.y)->getTexture() == DrawableObject::TEXTURE::GRASS)){
            dist[v4.x][v4.y] = dist[u.x][u.y] + 1;
            q.push(v4);
        }
    }

    if(dist[x][y] == -1){
        for (int i = 0; i < map->getWidth(); i++) {
            delete dist[i];
        }
        delete dist;
        return false;
    }

    path = new std::vector<sf::Vector2i>();
    int currentValue = dist[x][y];
    sf::Vector2i u;
    u.x = x;
    u.y = y;

    while(currentValue > 0){
        currentValue--;
        path->push_back(u);
        sf::Vector2i v1;
        v1.x = u.x - 1;
        v1.y = u.y;
        if(v1.x >= 0 && dist[v1.x][v1.y] == currentValue){
            u = v1;
            continue;
        }
        sf::Vector2i v2;
        v2.x = u.x + 1;
        v2.y = u.y;
        if(v2.x < map->getWidth() && dist[v2.x][v2.y] == currentValue){
            u = v2;
            continue;
        }
        sf::Vector2i v3;
        v3.x = u.x;
        v3.y = u.y - 1;
        if(v3.y >= 0 && dist[v3.x][v3.y] == currentValue){
            u = v3;
            continue;
        }
        sf::Vector2i v4;
        v4.x = u.x;
        v4.y = u.y + 1;
        if(v4.y < map->getHeight() && dist[v4.x][v4.y] == currentValue){
            u = v4;
            continue;
        }
    }

    std::reverse(path->begin(), path->end());

    for(sf::Vector2i v : *path){
        std::cout << v.x << " " << v.y << std::endl;
    }

    for (int i = 0; i < map->getWidth(); i++) {
        delete dist[i];
    }
    delete dist;

    return true;
}

int ObjectFiretruck::getNumberOfSandbags() {
    return numberOfSandbags;
}

void ObjectFiretruck::setNumberOfSandbags(int i) {
    numberOfSandbags = i;
}
