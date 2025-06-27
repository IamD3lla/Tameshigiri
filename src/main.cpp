#include <raylib.h>
#include <utils/utils.hpp>

int main() {
    InitWindow(windowDimension[0], windowDimension[1], "Songurai");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        Texture2D map = LoadTexture("assets/map_placeholder.png");

        DrawTextureEx(map, {0,0}, 0, SCALE, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
