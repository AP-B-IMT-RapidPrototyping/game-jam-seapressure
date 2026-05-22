//---------------------------
// Include Files
//---------------------------
#include "Pawn.h"

#include <algorithm>


//---------------------------
// Constructor & Destructor
//---------------------------
namespace game {
	Pawn::Pawn(const Texture2D &textureUsed, Vector2 startPosition, float speed)
		: position(startPosition), speed(speed), texture(&textureUsed) {
		//if (!IsTextureValid(*texture)){texture = &textureUsed;}
	}

	Pawn::~Pawn() = default;

	//---------------------------
	// Member functions
	//---------------------------

	// Write member functions here


	void Pawn::Update() {
		RandomMovement();
		ClampPos();
	}

	void Pawn::RandomMovement() {
		const float dt = GetFrameTime();
		const float randomX = static_cast<float>(GetRandomValue(-10, 10)) / 100.0f;
		const float randomY = static_cast<float>(GetRandomValue(-10, 10)) / 100.0f;

		velocity.x += randomX;
		velocity.y += randomY;


		velocity.x = std::clamp(velocity.x, -1.0f, 1.0f);
		velocity.y = std::clamp(velocity.y, -1.0f, 1.0f);
		position.x += velocity.x * speed * dt;
		position.y += velocity.y * speed * dt;
	}

	void Pawn::ClampPos() {
		auto maxX = static_cast<float>(GetScreenWidth() - texture->width);
		auto maxY = static_cast<float>(GetScreenHeight() - texture->height);
		maxX = std::max(0.0f, maxX);
		maxY = std::max(0.0f, maxY);


		position.x = std::clamp(position.x, 0.0f, maxX);
		position.y = std::clamp(position.y, 0.0f, maxY);
	}

	void Pawn::Draw() const {
		if (texture->id != 0) {
			DrawTextureEx(*texture, position, 0.f, 1.f, WHITE);
		}
	}

	Vector2 Pawn::GetPos() const {
		return position;
	}

	void Pawn::MoveTowards(const Vector2 &Pos) {

		const float dt = GetFrameTime();
		const float randomX = static_cast<float>(GetRandomValue(-10, 10)) / 100.0f;
		const float randomY = static_cast<float>(GetRandomValue(-10, 10)) / 100.0f;

		velocity.x = Pos.x-position.x;
		velocity.y = Pos.y-position.y;


		velocity.x = std::clamp(velocity.x, -1.0f, 1.0f);
		velocity.y = std::clamp(velocity.y, -1.0f, 1.0f);
		position.x += velocity.x * speed * dt;
		position.y += velocity.y * speed * dt;
	}
}

