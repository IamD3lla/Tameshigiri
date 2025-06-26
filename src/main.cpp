#include "raylib.h"

int main() {
    InitWindow(800, 600, "Raylib + VSCode no Arch");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Funciona!", 190, 200, 20, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
