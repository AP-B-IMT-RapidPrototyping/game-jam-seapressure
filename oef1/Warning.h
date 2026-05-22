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
// Warning Class									
//-----------------------------------------------------
class Warning final: public Pawn
{
public:
    using Pawn::Pawn;

    void Update();
};

}

 
