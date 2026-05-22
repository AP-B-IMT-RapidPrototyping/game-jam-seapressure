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

	const int X{GetScreenWidth() - tMonster.width};
	const int Y{GetScreenHeight() - tMonster.height};
	player=new Player(
		tPlayer,
		{static_cast<float>(X/2),
		static_cast<float>(Y/2)},
		200);
	monsterManager=new MonsterManager();
	gate=new Gate(		tPlayer,
		{static_cast<float>(X/2),
		static_cast<float>(Y/2)},
		200);
}

Game::~Game() {
	// for (Monster* monster : monsters) {
	// 	delete monster;
	// }
	// monsters.clear();
	delete monsterManager;
	delete player;
	delete gate;
	UnloadTexture(tPlayer);

	CloseWindow();
}

void Game::Update() {



	if (monsterManager->isLevelCleared || isLvcleared ) {
		++level;
		monsterManager->StartNewLevel(level + 2);
		bgc=bgcNext();
		gate->switchPos();
		isLvcleared=false;
	}

	if (std::abs(player->GetPos().x - gate->GetPos().x) < 40.f  &&
		std::abs(player->GetPos().y - gate->GetPos().y) < 40.f  ) {
		isLvcleared=true;
		}

	monsterManager->Update(player->GetPos());
	if (!isGameOver){
	player->Update();
	timer+= GetFrameTime();
	}


	if (monsterManager->isPlayerHit) {
		isGameOver=true;
	}
}

void Game::Draw() const {
	BeginDrawing();
	ClearBackground(bgc);
	gate->Draw(bgc);
	monsterManager->Draw();
	player->Draw();


	if (monsterManager->isPlayerHit) {


		DrawText("Game Over!", 20, 20, 20, DARKBLUE);
		DrawText(TextFormat("You managed to dive for %i meters", level*100), 20, 50, 20, MAROON);
		DrawText(TextFormat("and survived %i seconds", static_cast<int>(timer)), 20, 80, 20, MAROON);
	}

	EndDrawing();
}

bool Game::ShouldClose() {
	return WindowShouldClose();
}


	Color Game::bgcNext() const {

	return Color {
		static_cast<unsigned char>(std::max(bgc.r -5, 0 )), // put in clamp to ensure the int wouldn't cycle back up to 255 when subtracting past 0
		static_cast<unsigned char>(std::max(bgc.g -5, 0)),
		static_cast<unsigned char>(std::max(bgc.b -2, 0))
	};


}

	Color Game::bgcGate() const {
	return Color {
		static_cast<unsigned char>(std::max(bgc.r -100, 0 )), // put in clamp to ensure the int wouldn't cycle back up to 255 when subtracting past 0
		static_cast<unsigned char>(std::max(bgc.g -100, 0)),
		static_cast<unsigned char>(std::max(bgc.b -100, 0))
	};

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