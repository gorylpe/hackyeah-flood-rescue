//
// Created by Piotr on 28.10.2017.
//

#ifndef GRA_TILE_H
#define GRA_TILE_H

class Tile {
public:
    enum TILETYPE {
        WATER = 0,
        BUILDING = 1,
        GRASS = 2,
        FOREST = 3,
        ROAD = 4
    };
private:
    TILETYPE tileType;
    int height;

    bool sandbagsUp;
    bool sandbagsDown;
    bool sandbagsLeft;
    bool sandbagsRight;

public:
    Tile(TILETYPE _tileType, int _height);

    TILETYPE    getTileType(){return tileType;}
    int         getHeight(){return height;}

    void        setHeight(int newHeight){ height = newHeight; }
    void        setTileType(TILETYPE newTileType){ tileType = newTileType; }

    void        setSandbagsUp(bool set){sandbagsUp = set;}
    void        setSandbagsDown(bool set){sandbagsDown = set;}
    void        setSandbagsLeft(bool set){sandbagsLeft = set;}
    void        setSandbagsRight(bool set){sandbagsRight = set;}

    bool        getSandbagsUp(){ return sandbagsUp;}
    bool        getSandbagsDown(){ return sandbagsDown;}
    bool        getSandbagsLeft(){ return sandbagsLeft;}
    bool        getSandbagsRight(){ return sandbagsRight;}
};

#endif