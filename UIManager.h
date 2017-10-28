//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_UIMANAGER_H
#define GRA_UIMANAGER_H
#include "Object.h"

class UIManager {
    UIManager();
    UIManager(const UIManager&);

public:
    static UIManager& getSingleton();
    void handleClick(int x, int y);
};


#endif //GRA_UIMANAGER_H
