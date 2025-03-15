#pragma once
#include "types.h"

enum MachineType
{
    MachineType_None = 0,
    MachineType_Conveyor = 1,
    MachineType_UnderGroundBelt_In = 2,
    MachineType_UnderGroundBelt_Out = 3,
};

enum ActionType
{
    ActionType_None = 0,
    ActionType_Rotate = 1,
    ActionType_Destroy = 2,
    ActionType_Place = 3,
};

struct Port
{

};

enum Direction
{
    Direction_North = 0,
    Direction_East = 1,
    Direction_South = 2,
    Direction_West = 3,
};

struct Machine
{
    MachineType type;
    bool broken;
    Direction facing;
};

struct PendingAction
{
    ActionType type;

    MachineType placement_type;
    Direction facing;
};

struct Bomb
{
    i32 x;
    i32 y;
};

struct GameState
{
    i32 width;
    i32 height;

    Machine machine[27*27];
    PendingAction actions[27*27];

    Bomb bombs[27*27];
    u32 bomb_count;
};

extern GameState state;