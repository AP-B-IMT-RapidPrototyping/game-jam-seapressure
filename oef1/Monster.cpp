//---------------------------
// Include Files
//---------------------------
#include "Monster.h"


//---------------------------
// Constructor & Destructor
//---------------------------
namespace game
{
    void Monster::Update(const Vector2 &playerPos) {
        const float dt = GetFrameTime();
        if (isSpawning) {
            spawnTimer+=dt;
            if (spawnTimer>=SpawnTime) {
                isSpawning=false;
            }
            return;
        }

        MoveTowards(playerPos);
        ClampPos();
    }

}
