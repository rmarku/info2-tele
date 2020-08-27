#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    const float gravity = 0.5;
    float vel = 0;

    InitWindow(screenWidth, screenHeight, "Info II - Tele");
    Vector2 ballPosition = {(float) screenWidth / 2, (float) screenHeight / 2};
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP))
            vel = -4.0f;

        vel = vel + gravity;
        ballPosition.y = ballPosition.y + vel;

        if (ballPosition.y >= screenHeight) {
            vel = -vel;
            ballPosition.y = screenHeight;
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        DrawCircleV(ballPosition, 50, MAROON);
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}