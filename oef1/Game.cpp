#include "Game.h"

#include "raylib.h"

namespace game {

Game::Game() : width(800), height(600), fps(60) {
	InitWindow(width, height, "SeaPressure");
	SetTargetFPS(fps);

	// Load textures
	tPlayer = LoadTexture("src/MainCharacter.png");
	// tMonster = LoadTexture("src/enemy.png");

	// Load pawns

	//monsters.reserve(100);
	player=new Player(tPlayer,{},200);
	monsterManager=new MonsterManager();
}

Game::~Game() {
	// for (Monster* monster : monsters) {
	// 	delete monster;
	// }
	// monsters.clear();
	delete monsterManager;
	delete player;
	UnloadTexture(tPlayer);

	CloseWindow();
}

void Game::Update() {

	//Code here is written to allow the background to darken as the game progresses.
	if (IsKeyDown(KEY_SPACE)) {
		seaShade.r = std::max(seaShade.r -2, 0 ); // put in clamp to ensure the int wouldn't cycle back up to 255 when subtracting past 0
		seaShade.g = std::max(seaShade.g -2, 0);
		seaShade.b = std::max(seaShade.b -1, 0);
	}




	monsterManager->Update(player->GetPos());
	player->Update();

	if (monsterManager->isPlayerHit) {
		isGameOver=true;
	}
}

void Game::Draw() const {
	BeginDrawing();
	ClearBackground(seaShade);
	monsterManager->Draw();
	player->Draw();


	if (monsterManager->isPlayerHit) {


		DrawText("Game Over!", 20, 20, 20, DARKBLUE);
	}

	EndDrawing();
}

bool Game::ShouldClose() {
	return WindowShouldClose();
}

// void Game::SpawnMonster() {
// 	Vector2 spawnPos = {
// 		static_cast<float>(GetRandomValue(0, width - 1)),
// 		static_cast<float>(GetRandomValue(0, height - 1))
// 	};
//
// 	monsters.push_back(new Monster(tMonster,spawnPos));
// }

} // game