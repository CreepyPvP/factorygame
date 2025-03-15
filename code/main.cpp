#include "raylib.h"
#include "types.h"

#define TILE_SIZE 64

int main(void)
{
    i32 screenWidth = 800;
    i32 screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Factory game");

    SetTargetFPS(60);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (u32 x = 0; x < 15; ++x)
        {
            for (u32 y = 0; y < 15; ++y)
            {
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
