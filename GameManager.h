//
// Created by pietrk01 on 10/28/2017.
//

#include <SFML/Graphics.hpp>
#ifndef GRA_GAMEMANAGER_H
#define GRA_GAMEMANAGER_H


class GameManager {
    const double frameTime = 0;
    enum GAMESTATE{
            GAME,
            MENU
    };
    GAMESTATE gameState;
    bool isGameRunning;

    GameManager();
    GameManager(const GameManager &);
    ~GameManager();
public:
    static GameManager & getSingleton();
    void mainLoop();
};


#endif //GRA_GAMEMANAGER_H
