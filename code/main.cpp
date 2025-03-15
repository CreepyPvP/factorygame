#include "raylib.h"
#include "types.h"
#include "state.h"

#define TILE_SIZE 64

void LoadState()
{
    state = {};
    state.width = 10;
    state.height = 5;

    state.machine[5 + 3 * state.width].type = MachineType_Conveyor; 

    state.camera.target = {0, 0};
    // state.camera.offset = {(f32) GetScreenWidth() / 2.0f, (f32) GetScreenHeight() / 2.0f};
    state.camera.zoom = 100;
}

Color machine_colors[] = {
    BLUE,
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

        for (i32 x = 0; x < state.width; ++x)
        {
            for (i32 y = 0; y < state.height; ++y)
            {
                MachineType type = state.machine[x + y * state.width].type;

                if (type)
                {
                    continue;
                }
                
                DrawRectangle(x , y , 1, 1, machine_colors[type]);
            }
        }

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
