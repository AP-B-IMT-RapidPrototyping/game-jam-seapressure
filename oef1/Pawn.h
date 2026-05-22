#pragma once


#ifdef _MSVC_LANG
static_assert(_MSVC_LANG >= 201703L, "C++17 required");
#else
static_assert(__cplusplus >= 201703L, "C++17 required");
#endif



//-----------------------------------------------------
// Include Files
//-----------------------------------------------------

#include <string>

#include "raylib.h"
#include <iostream>

namespace game{
//-----------------------------------------------------
// Pawn Class									
//-----------------------------------------------------
class Pawn
{
public:
	Pawn(const Texture2D& textureUsed, Vector2 startPosition = {0.0f, 0.0f},float speed = 50.f);
	~Pawn();

	// -------------------------
	// Copy/move constructors and assignment operators
	// -------------------------    
	Pawn(const Pawn& other)					= default;
	Pawn(Pawn&& other) noexcept				= default;
	Pawn& operator=(const Pawn& other)		= default;
	Pawn& operator=(Pawn&& other)	noexcept	= default;

	//-------------------------------------------------
	// Member functions						
	//-------------------------------------------------


	void Update();
	void Draw() const;
	[[nodiscard]] Vector2 GetPos() const;

protected:
	//-------------------------------------------------
	// Protected member functions
	//-------------------------------------------------


	void RandomMovement();
	void MoveTowards(const Vector2 &Pos);
	void ClampPos();

	//-------------------------------------------------
	// Datamembers								
	//-------------------------------------------------

	const Texture2D* texture{};
	Vector2 position{};
	Vector2 velocity{0.f,0.f};
	float speed{};


};

}

 
