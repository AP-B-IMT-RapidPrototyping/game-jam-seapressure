//---------------------------
// Include Files
//---------------------------
#include "Player.h"
#include "raymath.h"

#include "raylib.h"
#include <iostream>

//---------------------------
// Constructor & Destructor
//---------------------------
namespace game
{

    void Player::Update() {
        const float dt = GetFrameTime();

        Vector2 direction{0,0};

        if (IsKeyDown(KEY_UP)) direction.y=-1;
        if (IsKeyDown(KEY_DOWN)) direction.y=1;
        if (IsKeyDown(KEY_LEFT)) direction.x=-1;
        if (IsKeyDown(KEY_RIGHT)) direction.x=1;
        direction=Vector2Normalize(direction);

        position.x += direction.x * speed * dt;
        position.y += direction.y * speed * dt;
        ClampPos();
    }
}