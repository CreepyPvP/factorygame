#pragma once
#include "types.h"

enum MachineType
{
    MachineType_None,
    MachineType_Conveyor,
    MachineType_UnderGroundBelt_In,
    MachineType_UnderGroundBelt_Out,
};

enum ActionType
{
    ActionType_None,
    ActionType_Rotate,
    ActionType_Destroy,
    ActionType_Place,
};

enum Direction
{
    Direction_North,
    Direction_East,
    Direction_South,
    Direction_West,
};

struct Port
{
    i32 x;
    i32 y;
    Direction facing;
    bool in;
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

    u32 port_count;
    Port ports[16];
};

extern GameState state;