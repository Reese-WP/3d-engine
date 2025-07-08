#include "raylib.h"
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

    //cam init
    Vector3 position = (Vector3){ 0.0f, 2.0f, 0.0f };

    Camera camera  = { 0 };

    // Define camera (position, target, up vector)
    camera.position = position;    // Camera position
    camera.target = (Vector3){position.x - 1, position.y, position.z};      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

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

        if(IsCursorHidden())
        {
            UpdateCameraPro(&camera,
                Vector3{
                    (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.1f - (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.1f,                                  // Move forward-backward
                    (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.1f - (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.1f,                               // Move right-left
                    (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_RIGHT_SHIFT))*0.1f - (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_CONTROL))*0.1f    // Move up-down
                },
                Vector3{
                    GetMouseDelta().x * 0.05f,                            // Rotation: yaw
                    GetMouseDelta().y * 0.05f,                            // Rotation: pitch
                    0.0f                                                // Rotation: roll
                },
                0.0f);                              // Move to target (zoom)   GetMouseWheelMove()*2.0f
        }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D((camera));

                DrawCube(Vector3{0,0,0}, 1, 1, 1, RED);
                
            EndMode3D();

            DrawFPS(10, 10);
            DrawText("Press TAB to toggle cursor visibility", 10, 30, 20, DARKGRAY);
            DrawText("Use W, A, S, D, SPACE and SHIFT to move", 10, 50, 20, DARKGRAY);
            DrawText("Use mouse to look around", 10, 70, 20, DARKGRAY);
            DrawText("context grid", 10, 100, 20, DARKGRAY);
            DrawTexture(sad_, 140, 98, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}