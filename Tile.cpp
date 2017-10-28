//
// Created by Piotr on 28.10.2017.
//

#include "Tile.h"

Tile::Tile(Tile::TILETYPE _tileType, int _height)
    :tileType(_tileType)
    ,height(_height)
    ,sandbagsDown(false)
    ,sandbagsUp(false)
    ,sandbagsLeft(false)
    ,sandbagsRight(false)
{}
