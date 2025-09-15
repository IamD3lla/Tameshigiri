#include <raylib.h>
#include <utils/utils.hpp>
#include <player/include/player.hpp>

int main() {

    Player player(windowDimension[0], windowDimension[1]);

    InitWindow(windowDimension[0], windowDimension[1], "Tameshigiri");

    Texture2D map = LoadTexture("../assets/map_placeholder.png");
    Vector2 mapPos{0,0};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTextureEx(map, mapPos, 0, SCALE, WHITE);

        player.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
    return 0;
}