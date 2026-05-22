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
        RandomMovement();
        ClampPos();
    }
}
