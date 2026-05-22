//---------------------------
// Include Files
//---------------------------
#include "Warning.h"


//---------------------------
// Constructor & Destructor
//---------------------------
namespace game
{


    void Warning::Update() {
       const float dt = GetFrameTime();
       // Increase timer by dt
    timer+=dt;
    }

    bool Warning::IsExpired() const {
        return (timer >= Lifetime);
    }
}
