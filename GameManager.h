//
// Created by pietrk01 on 10/28/2017.
//

#include <SFML/Graphics.hpp>
#ifndef GRA_GAMEMANAGER_H
#define GRA_GAMEMANAGER_H


class GameManager {
    // milliseconds
    sf::Time frameTime;
    enum GAMESTATE{
            GAME,
            MENU
    };
    GAMESTATE gameState;
    bool isGameRunning;

    GameManager();
    GameManager(const GameManager &);
    ~GameManager();

    void gameLoop();
public:
    static GameManager & getSingleton();
    void mainLoop();
    void setFrameTime(int time);
};


#endif //GRA_GAMEMANAGER_H
