#pragma once

#include "types.h"

enum TileType
{
    TileType_None,
    TileType_Conveyor,
};

struct Tile
{
    TileType type;
};

struct Port
{
    i32 x;
    i32 y;
};

struct GameState
{
    i32 width;
    i32 height;

    Tile tiles[128];
};

extern GameState state;