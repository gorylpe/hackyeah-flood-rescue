//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_UIMANAGER_H
#define GRA_UIMANAGER_H
#include "Object.h"
#include "UIElement.h"

class UIManager {
    std::vector<UIElement*> *elements;
    UIManager();
    UIManager(const UIManager&);

public:
    static UIManager& getSingleton();
    void handleClick(int x, int y);
    void draw(sf::RenderWindow *window);
    void addElement(UIElement *element);
};


#endif //GRA_UIMANAGER_H
