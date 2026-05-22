//
// Created by marsd on 26/03/2026.
//

#include "MonsterManager.h"

namespace game {
    MonsterManager::MonsterManager() {
        tMonster = LoadTexture("src/Enemy.png");
        tWarning = LoadTexture("src/warning.png");
        monsters.reserve(50);
        warnings.reserve(50);
    }

    MonsterManager::~MonsterManager() {
        for (Monster *monster: monsters) {
            delete monster;
        }

        monsters.clear();
        for (Warning *warning: warnings) {
            delete warning;
        }

        warnings.clear();
        UnloadTexture(tMonster);
        UnloadTexture(tWarning);
    }

    void MonsterManager::Update(const Vector2 &playerPos) {
        float dt = GetFrameTime();
        if (IsKeyPressed(KEY_S)) {
            SpawnMonster();
        }
        for (auto it = warnings.begin(); it != warnings.end();) {
            Warning *warning = *it;
            warning->Update();
            if (warning->IsExpired()) {

                delete warning;
                it = warnings.erase(it);
            } else {
                ++it;
            }

        }


        for (auto it = monsters.begin(); it != monsters.end();) {
            Monster *monster = *it;

            monster->Update();
            if (monster->isGonnaAttack) {
                //spawn warning

                // turn it off
                monster->isGonnaAttack=false;

            }


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

        for (const Warning *warning: warnings) {
            warning->Draw();
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
        warnings.push_back(new Warning(tWarning, spawnPos));
    }

    void MonsterManager::SpawnMonsterBatch(int amount) {
        for (int i = 0; i < amount; ++i) {
            SpawnMonster();

        }
    }
} // game
