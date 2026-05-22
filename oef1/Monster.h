#pragma once


#ifdef _MSVC_LANG
static_assert(_MSVC_LANG >= 201703L, "C++17 required");
#else
static_assert(__cplusplus >= 201703L, "C++17 required");
#endif



//-----------------------------------------------------
// Include Files
//-----------------------------------------------------

#include "Pawn.h"
namespace game{
//-----------------------------------------------------
// Monster Class									
//-----------------------------------------------------
class Monster final: public Pawn
{
public:
    using Pawn::Pawn;

    void Update();
    void Update(const Vector2 &playerPos);
    bool isGonnaAttack{false};
    bool isSpawning{true};



private:
    const float SpawnTime{1.f};
    float spawnTimer{0.f};
};

}

 
