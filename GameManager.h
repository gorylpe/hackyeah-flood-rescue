//
// Created by pietrk01 on 10/28/2017.
//

#include <SFML/Graphics.hpp>
#ifndef GRA_GAMEMANAGER_H
#define GRA_GAMEMANAGER_H
#include "DrawingManager.h"
#include "GameManager.h"
#include "Map.h"


class GameManager {
    // milliseconds
    sf::Time frameTime;
    enum GAMESTATE{
            GAME,
            MENU
    };
    GAMESTATE gameState;
    bool isGameRunning;
    Map *map;

    GameManager();
    GameManager(const GameManager &);
    ~GameManager();

    void gameLoop();
    void handleEvents();

    void resetMap();
public:
    static GameManager & getSingleton();
    void mainLoop();
    void setFrameTime(int time);

    void doObjectsIteration();

    Map* getMap(){return map;};
};


#endif //GRA_GAMEMANAGER_H
