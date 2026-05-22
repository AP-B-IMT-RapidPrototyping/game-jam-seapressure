//---------------------------
// Include Files
//---------------------------
#include "Monster.h"


//---------------------------
// Constructor & Destructor
//---------------------------
namespace game
{
    void Monster::Update() {
        const float dt = GetFrameTime();
        if (isSpawning) {
            spawnTimer+=dt;
            if (spawnTimer>=SpawnTime) {
                isSpawning=false;
            }
            return;
        }

        RandomMovement();
        ClampPos();
    }

    void Monster::Draw() const {
        if (isSpawning) return;
        if (texture->id != 0) {
            DrawTextureV(*texture, position, WHITE);
        }

    }
}
