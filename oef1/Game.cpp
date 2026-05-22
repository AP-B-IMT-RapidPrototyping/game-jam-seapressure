#include "Game.h"

#include "raylib.h"

namespace game {

Game::Game() : width(800), height(600), fps(60) {
	InitWindow(width, height, "Monster Spawner");
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
	// UnloadTexture(tMonster);

	CloseWindow();
}

void Game::Update() {

	// if (IsKeyPressed(KEY_S)) {
	// 	SpawnMonster();
	// }
	//
	// for (auto it = monsters.begin(); it != monsters.end();) {
	// 	Monster* monster = *it;
	// 	monster->Update();
	//
	// 	if (std::abs(monster->GetPos().x - player->GetPos().x) < 50.f &&
	// 		std::abs(monster->GetPos().y - player->GetPos().y) < 50.f) {
	// 		delete monster;
	// 		it = monsters.erase(it);
	// 	} else {
	// 		++it;
	// 	}
	// }
	monsterManager->Update(player->GetPos());
	player->Update();
}

void Game::Draw() const {
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// for (const Monster* monster : monsters) {
	// 	monster->Draw();
	// }
	monsterManager->Draw();
	player->Draw();
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