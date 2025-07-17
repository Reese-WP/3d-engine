#ifndef PLAYER_H
#define PLAYER_H

//#include "raymath.h"
#include "raylib.h"

class Player
{
private:
    Camera camera  = { 0 };

    bool canFly;
    bool canJump;
    bool canSprint;
    bool hasGravity;

    int stamina = 100000;
public:
    Player(Vector3 position = Vector3{0, 0, 0}, Vector3 target = Vector3{1, 0, 0}, float fov = 45.0f, bool canFly = false, bool canJump = false,  bool canSprint = false, bool hasGravity = false);
    ~Player();

    void updatePos();

    Camera* getCamera();
    bool getCanFly();
    bool getCanJump();
    bool getCanSprint();
    bool getHasGravity();

    void setCanFly(bool canFly);
    void setCanJump(bool canJump);
    void setCanSprint(bool canSprint);
    void setHasGravity(bool hasGravity);
};

#endif