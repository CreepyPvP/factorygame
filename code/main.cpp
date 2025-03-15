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
    state.height = 5;

    state.machine[5 + 3 * state.width].type = MachineType_Conveyor; 

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

int main(void)
{
    InitWindow(1600, 900, "Factory game");

    SetTargetFPS(60);

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
                MachineType type = state.machine[x + y * state.width].type;

                if (!type)
                {
                    continue;
                }
                
                DrawRectangle(x , y , 1, 1, machine_colors[type]);
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
