#include "raylib.h"

typedef struct {
    float velocidad;
    Texture2D texture;
    Vector2 pos;
} Entidad;

void DrawEntidad(Entidad ent) {
    DrawTextureV(ent.texture, ent.pos, WHITE);
}

void MoverEntidad(Entidad *ent) {
    ent->pos.x += 0.2;
}


int main(void) {
    const int screenWidth = 512;
    const int screenHeight = 366;

    const float gravity = 0.5;

    InitWindow(screenWidth, screenHeight, "Info II - Tele");
    Entidad nave;
    Entidad enemigos[5];

    for (int i = 0; i < 5; ++i) {
        enemigos[i].texture = LoadTexture("nave.png");        // Texture loading
        enemigos[i].pos.x = 33 * i;
        enemigos[i].pos.y = 33 * i;
        enemigos[i].velocidad = 0;
    }

    nave.texture = LoadTexture("nave.png");        // Texture loading
    nave.pos.x = (float) screenWidth / 2 - nave.texture.width / 2;
    nave.pos.y = (float) screenHeight / 2 - nave.texture.height / 2;
    nave.velocidad = 0;

    float fondoX = 0;
    Texture2D fondo = LoadTexture("fondo.png");        // Texture loading


    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP))
            nave.velocidad = -4.0f;
        if (IsKeyDown(KEY_RIGHT))
            nave.pos.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))
            nave.pos.x -= 2.0f;

        nave.velocidad = nave.velocidad + gravity;
        nave.pos.y = nave.pos.y + nave.velocidad;

        if (nave.pos.y >= screenHeight) {
            nave.velocidad = -nave.velocidad;
            nave.pos.y = screenHeight;
        }

        fondoX -= 1.5;
        if (fondoX < -fondo.width) {
            fondoX += fondo.width;
        }
        for (int i = 0; i < 5; ++i) {
            MoverEntidad(&enemigos[i]);
        }


        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(fondo, fondoX, 0, WHITE);
        DrawTexture(fondo, fondo.width + fondoX, 0, WHITE);


        DrawEntidad(nave);
        for (int i = 0; i < 5; ++i) {
            DrawEntidad(enemigos[i]);
        }

        DrawText("Nave", 10, 10, 20, DARKGRAY);
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}