//
// Created by CLion on 28.10.2017.
//

#ifndef GRA_MAP_H
#define GRA_MAP_H

class Map {
public:
    Map(int _width, int _height);
    unsigned int getWaterLevel(int x, int y);
    void setWaterLevel(int x, int y, int level);
private:
    int width, height;
    int **waterLevels;
};


#endif //GRA_MAP_H
