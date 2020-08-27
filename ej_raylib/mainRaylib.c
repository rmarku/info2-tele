#include "raylib.h"

int main(void) {
    const int screenWidth = 512;
    const int screenHeight = 366;

    const float gravity = 0.5;
    float vel = 0;
    float fondoX = 0;

    InitWindow(screenWidth, screenHeight, "Info II - Tele");
    Texture2D nave = LoadTexture("nave.png");        // Texture loading
    Texture2D fondo = LoadTexture("fondo.png");        // Texture loading

    Vector2 navePos = {
            (float) screenWidth / 2 - nave.width / 2,
            (float) screenHeight / 2 - nave.height / 2
    };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP))
            vel = -4.0f;
        if (IsKeyDown(KEY_RIGHT))
            navePos.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))
            navePos.x -= 2.0f;

        vel = vel + gravity;
        navePos.y = navePos.y + vel;

        if (navePos.y >= screenHeight) {
            vel = -vel;
            navePos.y = screenHeight;
        }

        fondoX -= 1.5;
        if (fondoX < -fondo.width) {
            fondoX += fondo.width;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(fondo, fondoX, 0, WHITE);
        DrawTexture(fondo, fondo.width + fondoX, 0, WHITE);
        DrawTexture(nave, navePos.x, navePos.y, WHITE);
        DrawText("Nave", 10, 10, 20, DARKGRAY);
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}