#include "raylib.h"
#include "types.h"
#include "state.h"

#define TILE_SIZE 64

void LoadState()
{
    state = {};
    state.width = 10;
    state.height = 5;

    state.tiles[5 + 3 * state.width].type = TileType_Conveyor; 
}

int main(void)
{
    i32 screenWidth = 800;
    i32 screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Factory game");

    SetTargetFPS(60);

    LoadState();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (u32 x = 0; x < state.width; ++x)
        {
            for (u32 y = 0; y < state.height; ++y)
            {
                if (state.tiles[x + y * state.width].type)
                {
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
