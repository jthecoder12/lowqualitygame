#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// The worst possible game
int main() {
    InitWindow(1234, 1234, "🎮");
    SetTargetFPS(19);

    Texture2D 💬 = LoadTexture("Untitled.png");
    Texture2D 🗨️ = LoadTexture("Untitled.jpg");
    Texture2D 🟢 = LoadTexture("Untitled.bmp");

    InitAudioDevice();

    Music 🔊 = LoadMusicStream("Untitled.ogg");
    🔊.looping = true;

    int 🦤 = 800, 🐔 = 100;
    int 🍎 = 0, 🥀 = 0;

    int 🦩[4] = {100, 400, 600, 800};
    int 🐦[6] = {100, 300, 500, 700, 900, 1100};

    bool win = false;

    srand(time(NULL));    

    PlayMusicStream(🔊);

    while(!WindowShouldClose()) {
        BeginDrawing();

        UpdateMusicStream(🔊);

        char 🐜[1234];
        strcpy(🐜, "FPS: ");
        char 🐛[5678];
        sprintf(🐛, "%d", GetFPS());
        strcat(🐜, 🐛);

        if(IsKeyPressed(KEY_APOSTROPHE)) {
            🍎 = 🦩[rand()%5];
            🥀 = 🐦[rand()%7];
            🦤 += 200;
        }
        else if(IsKeyPressed(KEY_BACKSLASH)) {
            🍎 = 🦩[rand()%5];
            🥀 = 🐦[rand()%7];
            🦤 -= 200;
        }
        else if(IsKeyPressed(KEY_TAB)) {
            🍎 = 🦩[rand()%5];
            🥀 = 🐦[rand()%7];
            🐔 -= 200;
        }
        else if(IsKeyPressed(KEY_ZERO)) {
            🍎 = 🦩[rand()%5];
            🥀 = 🐦[rand()%7];
            🐔 += 200;
        }

        DrawTexture(🟢, 100, 100, WHITE);
        DrawTexture(🟢, 400, 100, WHITE);
        DrawTexture(🟢, 600, 100, WHITE);
        DrawTexture(🟢, 800, 100, WHITE);

        DrawTexture(🟢, 100, 300, WHITE);
        DrawTexture(🟢, 400, 300, WHITE);
        DrawTexture(🟢, 600, 300, WHITE);
        DrawTexture(🟢, 800, 300, WHITE);
        
        DrawTexture(🟢, 100, 500, WHITE);
        DrawTexture(🟢, 400, 500, WHITE);
        DrawTexture(🟢, 600, 500, WHITE);
        DrawTexture(🟢, 800, 500, WHITE);

        DrawTexture(🟢, 100, 700, WHITE);
        DrawTexture(🟢, 400, 700, WHITE);
        DrawTexture(🟢, 600, 700, WHITE);
        DrawTexture(🟢, 800, 700, WHITE);

        DrawTexture(🟢, 100, 900, WHITE);
        DrawTexture(🟢, 400, 900, WHITE);
        DrawTexture(🟢, 600, 900, WHITE);
        DrawTexture(🟢, 800, 900, WHITE);

        DrawTexture(🟢, 100, 1100, WHITE);
        DrawTexture(🟢, 400, 1100, WHITE);
        DrawTexture(🟢, 600, 1100, WHITE);
        DrawTexture(🟢, 800, 1100, WHITE);

        DrawTexture(🗨️, 🍎, 🥀, WHITE);
        Rectangle 🧃 = {🍎, 🥀, 280, 245};
        Rectangle 🎁 = {🦤, 🐔, 280, 245};
        if(CheckCollisionRecs(🧃, 🎁)) memset((void*) 123, 123, 123);

        Rectangle 🗳️ = {100, 1200, 280, 245};
        if(CheckCollisionRecs(🗳️, 🎁)) win = true;
        if(win) DrawText("You win", 100, 100, 100, BLACK);

        ClearBackground(RAYWHITE);
        DrawText(🐜, 200, 0, 60, BLACK);
        DrawTexture(💬, 🦤, 🐔, WHITE);
        EndDrawing();
    }

    // Don't free resources
    return 123;
}
