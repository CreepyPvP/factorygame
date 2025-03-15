#include "raylib.h"
#include "rlgl.h"

#include "types.h"
#include "state.h"
#include "edit_phase.h"

#define TILE_SIZE 64

void LoadState()
{
    state = {};
    state.width = 10;
    state.height = 10;

    state.machine[5 + 3 * state.width].type = MachineType_Conveyor; 
    state.machine[5 + 3 * state.width].facing = Direction_East; 

    state.machine[5 + 4 * state.width].type = MachineType_Conveyor; 
    state.machine[5 + 4 * state.width].facing = Direction_North; 

    state.machine[5 + 5 * state.width].type = MachineType_Conveyor; 
    state.machine[5 + 5 * state.width].facing = Direction_West; 

    state.machine[5 + 6 * state.width].type = MachineType_Conveyor; 
    state.machine[5 + 6 * state.width].facing = Direction_South; 

    state.camera.target = {-1, -1};
    // state.camera.offset = {(f32) GetScreenWidth() / 2.0f, (f32) GetScreenHeight() / 2.0f};
    state.camera.zoom = 100;

    state.port_count = 2;
    state.ports[0].x = -1;
    state.ports[0].y = 4;
    state.ports[0].in = true;

    state.ports[1].x = state.width + 1;
    state.ports[1].y = 2;
}

Color machine_colors[] = {
    WHITE,
    BLUE,
    GREEN,
    RED,
};

f32 facing_rotations[] = {
    0,      // Direction_North,
    270,        // Direction_East,
    180,        // Direction_South,
    90,        // Direction_West,
};

Vector2 facing_offsets[] = {
    v2(0, 0),
    v2(0, 1),
    v2(1, 1),
    v2(1, 0),
};

Texture2D conveyor_straight;

int main(void)
{
    InitWindow(1600, 900, "Factory game");

    SetTargetFPS(60);

    conveyor_straight = LoadTexture("assets/machines/conveyor_straight.png");

    LoadState();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D(state.camera);
        ClearBackground(RAYWHITE);

        UpdateEditPhase();

        DrawRectangle(state.editor.hovered_pos.x, state.editor.hovered_pos.y, 1, 1, LIGHTGRAY);

        DrawGrid(50, 1);

        for (i32 x = 0; x < state.width; ++x)
        {
            for (i32 y = 0; y < state.height; ++y)
            {
                Machine *machine = state.machine + (x + y * state.width);

                if (!machine->type)
                {
                    continue;
                }

                Vector2 pos = v2(x + facing_offsets[machine->facing].x, y + facing_offsets[machine->facing].y);
                DrawTexturePro(conveyor_straight, {0, 0, 128, 128}, {pos.x, pos.y, 1, 1}, {}, facing_rotations[machine->facing], WHITE);
            }
        }

        for (u32 i = 0; i < state.port_count; ++i)
        {
            Port *port = state.ports + i;

            Color color = BLACK;

            if (port->in)
            {
                color = YELLOW;
            }

            DrawRectangle(port->x, port->y, 1, 1, color);
        }

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
