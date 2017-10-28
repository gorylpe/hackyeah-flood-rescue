//
// Created by pietrk01 on 10/28/2017.
//

#ifndef GRA_GAMEMANAGER_H
#define GRA_GAMEMANAGER_H


class GameManager {
    const double frameTime = 0;
    GameManager();
    GameManager(const GameManager &);
    ~GameManager();
public:
    static GameManager & getSingleton();
    void mainLoop();
};


#endif //GRA_GAMEMANAGER_H
