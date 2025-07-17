#include "raylib.h"
#include "player/Player.h"
#include <string>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "☭ Our Window ☭");

    //texture rend
    Image sad = LoadImage("../assets/emotions/white_frowning_face_u2639_icon_24x24.png");
    Texture2D sad_ = LoadTextureFromImage(sad);
    UnloadImage(sad);

    //define player
    Player player(Vector3{0,1.6,0}, Vector3{1,1.6,0}, 45.0f, false, false, true, false);

    DisableCursor();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_TAB))   // Toggle cursor visibility
        {
            if (IsCursorHidden()) {EnableCursor();}
            else {DisableCursor();}
        }

        if(IsKeyPressed(KEY_F4))
        {
            if(GetScreenHeight() == screenHeight)
            {
                int monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();
            }
            else
            {
                SetWindowSize(screenWidth, screenHeight);
                ToggleFullscreen();
            }
        }
        
        if(IsCursorHidden())
        {
            player.updatePos();
        }

        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            BeginMode3D(*(player.getCamera()));

                DrawCube(Vector3{0,1,0}, 1, 2, 1, RED);
                DrawPlane(Vector3{0,0,0},Vector2{500,500}, DARKGRAY);                
            EndMode3D();

            DrawFPS(10, 10);
            DrawText("Press TAB to toggle cursor visibility", 10, 30, 20, BLACK);
            DrawText("Use W, A, S, D, SPACE and SHIFT to move", 10, 50, 20, BLACK);
            DrawText("Use mouse to look around", 10, 70, 20, BLACK);
            //DrawText("context grid:", 10, 100, 20, DARKGRAY);
            //DrawTexture(sad_, 140, 98, DARKGRAY);
            //DrawText(std::to_string((int)(stamina/1000)).c_str(), 10, 880, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}