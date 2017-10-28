//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_DRAWINGMANAGER_H
#define GRA_DRAWINGMANAGER_H


#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Map.h"
#include "Object.h"
#include "Tile.h"

class DrawingManager {
public:
    enum MOVEDIR{
        LEFT,
        RIGHT,
        TOP,
        BOTTOM
    };
private:
    DrawingManager();
    DrawingManager(const DrawingManager&){};

    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow* window;

    int tileWidth = 40;
    int tileHeight = 40;
    //viewport
    int vx = 0;
    int vy = 0;
    int vw = windowWidth / tileWidth;
    int vh = windowHeight / tileHeight;

    void loadSprites();

    std::map<Tile::TILETYPE, sf::Texture*>* textureMap;
public:
    static DrawingManager& getSingleton(){
        static DrawingManager singleton;
        return singleton;
    }

    sf::RenderWindow* getWindow(){return window;}

    void draw(Map* map, std::vector<Object*>* objectsArray);

    void moveViewport(Map* map, MOVEDIR dir);
};


#endif //GRA_DRAWINGMANAGER_H
