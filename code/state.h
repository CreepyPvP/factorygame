#pragma once
#include "game_math.h"
#include "raylib.h"
#include "types.h"

enum MachineType
{
    MachineType_None,

    MachineType_Conveyor,
    MachineType_UnderGroundBelt_In,
    MachineType_UnderGroundBelt_Out,

    MachineType_Count,
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


struct PendingAction
{
    ActionType type;

    // Only use if ActionType_Place
    MachineType placement_type;
    // Only use if ActionType_Place or ActionType_Rotate
    Direction facing;
};

struct Machine
{
    MachineType type;
    bool broken;
    Direction facing;

    PendingAction action;
};

struct Bomb
{
    Vec2I position;

    u32 size_ext; // size is (1 + 2 * size_ext)
};


struct Test
{
    Vec2I pos;
};

struct EditorData
{
    Vec2I hovered_pos;
    MachineType hovered_type;
    Direction hovered_direction;
};

struct GameState
{
    i32 width;
    i32 height;

    Machine machine[27*27];

    Bomb bombs[27*27];
    u32 bomb_count;

    u32 port_count;
    Port ports[16];


    Camera2D camera;

    EditorData editor;
};

extern GameState state;