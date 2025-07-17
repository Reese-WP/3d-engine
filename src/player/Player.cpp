//#include "raymath.h"
#include "raylib.h"
#include "Player.h"
#include <string>

Player::Player(Vector3 position, Vector3 target, float fov, bool canFly, bool canJump,  bool canSprint, bool hasGravity)
{
    // Define camera (position, target, up vector)
    camera.position = position;    // Camera position
    camera.target = target;      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = fov;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    this->canFly = canFly;
    this->canJump = canJump;
    this->canSprint = canSprint;
    this->hasGravity = hasGravity;
}

Player::~Player()
{
}

//setters
void Player::setCanFly(bool canFly)
{
    this->canFly = canFly;
}
void Player::setCanJump(bool canJump)
{
    this->canJump = canJump;
}
void Player::setCanSprint(bool canSprint)
{
    this->canSprint = canSprint;
}
void Player::setHasGravity(bool hasGravity)
{
    this->hasGravity = hasGravity;
}

//getters
Camera* Player::getCamera()
{
    return &camera;
}
bool Player::getCanFly()
{
    return canFly;
}
bool Player::getCanJump()
{
    return canJump;
}
bool Player::getCanSprint()
{
    return canSprint;
}
bool Player::getHasGravity()
{
    return hasGravity;
}

//updaters
void Player::updatePos()
{
    UpdateCameraPro(&camera,
        Vector3{
            ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0.05f - (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0.05f) * (1 + IsKeyDown(KEY_LEFT_SHIFT)),                                  // Move forward-backward
            ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0.05f - (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0.05f) * (1 + IsKeyDown(KEY_LEFT_SHIFT)),                               // Move right-left
            ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_RIGHT_SHIFT))*0.05f - (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_CONTROL))*0.05f) * (1 + IsKeyDown(KEY_LEFT_SHIFT)) * canFly      // Move up-down
        },
        Vector3{
            GetMouseDelta().x * 0.05f,                            // Rotation: yaw
            GetMouseDelta().y * 0.05f,                            // Rotation: pitch
            0.0f                                                // Rotation: roll
        },
        0.0f);                              // Move to target (zoom)   GetMouseWheelMove()*2.0f
    if(canSprint)
    {
        if(IsKeyDown(KEY_LEFT_SHIFT) && stamina > 0) stamina -= 250;
        else if (stamina < 100000) stamina += 63;
    }
}
