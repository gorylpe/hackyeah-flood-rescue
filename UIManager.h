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
    void handleClick(Object *object);
};


#endif //GRA_UIMANAGER_H
