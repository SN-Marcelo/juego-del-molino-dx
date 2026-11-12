#include <raylib.h>

#include "game.h"
#include "colors.h"

int main()
{
    InitWindow(500, 620, "Juego del molino");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}