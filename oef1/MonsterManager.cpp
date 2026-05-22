//
// Created by marsd on 26/03/2026.
//

#include "MonsterManager.h"

namespace game {
    MonsterManager::MonsterManager() {
        tMonster = LoadTexture("src/enemy.png");
        monsters.reserve(50);
    }

    MonsterManager::~MonsterManager() {
        for (Monster *monster: monsters) {
            delete monster;
        }

        monsters.clear();
        UnloadTexture(tMonster);
    }

    void MonsterManager::Update(const Vector2 &playerPos) {
        if (IsKeyPressed(KEY_S)) {
            SpawnMonster();
        }


        for (auto it = monsters.begin(); it != monsters.end();) {
            Monster *monster = *it;
            monster->Update();

            if (std::abs(monster->GetPos().x - playerPos.x) < 50.f &&
                std::abs(monster->GetPos().y - playerPos.y) < 50.f) {
                delete monster;
                it = monsters.erase(it);
            } else {
                ++it;
            }
        }
    }

    void MonsterManager::Draw() const {
        for (const Monster *monster: monsters) {
            monster->Draw();
        }


        DrawText("Druk op S om een monster te spawnen", 20, 20, 20, DARKBLUE);
        DrawText(TextFormat("Aantal monsters: %i", static_cast<int>(monsters.size())), 20, 50, 20, MAROON);
    }

    void MonsterManager::SpawnMonster() {
        const int maxX{GetScreenWidth() - tMonster.width};
        const int maxY{GetScreenHeight() - tMonster.height};


        Vector2 spawnPos = {
            static_cast<float>(GetRandomValue(0, maxX - 1)),
            static_cast<float>(GetRandomValue(0, maxY - 1))
        };

        monsters.push_back(new Monster(tMonster, spawnPos));
    }

    void MonsterManager::SpawnMonsterBatch(int amount) {
        for (int i = 0; i < amount; ++i) {
            SpawnMonster();

        }
    }
} // game
