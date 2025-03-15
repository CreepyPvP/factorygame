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

struct GameState
{
    u32 width;
    u32 height;

    Tile tiles[128];
};

extern GameState state;