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

public:
    Tile(TILETYPE _tileType, int _height)
    :tileType(_tileType)
    ,height(_height){}

    TILETYPE    getTileType(){return tileType;}
    int         getHeight(){return height;}

    void        setHeight(int newHeight){ height = newHeight; }
    void        setTileType(TILETYPE newTileType){ tileType = newTileType; }

};