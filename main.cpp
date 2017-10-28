#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "GameManager.h"

int main() {
   GameManager::getSingleton().mainLoop();
    return 0;
}