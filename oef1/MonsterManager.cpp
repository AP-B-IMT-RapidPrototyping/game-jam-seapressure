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

        if (IsKeyPressed(KEY_P)) {
            isLevelCleared=true;
        }

        if (isPlayerHit) return;

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

            monster->Update(playerPos);
            if (monster->isGonnaAttack) {
                //spawn warning

                // turn it off
                monster->isGonnaAttack=false;

            }

            if (!monster->isSpawning &&
                std::abs(monster->GetPos().x - playerPos.x) < 30.f &&
                std::abs(monster->GetPos().y - playerPos.y) < 30.f) {
                // // player hit
                isPlayerHit=true;

                return;

                // delete monster;
                // it = monsters.erase(it);
            }
            ++it;
        }
    }

    void MonsterManager::Draw() const {
        for (const Monster *monster: monsters) {
            if (!monster->isSpawning){
            monster->Draw();
            }

        }

        for (const Warning *warning: warnings) {
            warning->Draw();
        }


        //DrawText("Druk op S om een monster te spawnen", 20, 20, 20, DARKBLUE);
        //DrawText(TextFormat("Aantal monsters: %i", static_cast<int>(monsters.size())), 20, 50, 20, MAROON);
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

    void MonsterManager::StartNewLevel(int enemyAmount) {
        // remove everything
        for (Monster *monster: monsters) {
            delete monster;
        }

        monsters.clear();
        for (Warning *warning: warnings) {
            delete warning;
        }

        warnings.clear();

        // Add in enemies
        SpawnMonsterBatch(enemyAmount);

        isLevelCleared=false;
    }

    void MonsterManager::StartNewGame(int enemyAmount) {
        isPlayerHit=false;

        StartNewLevel(enemyAmount + 1);
    }
} // game
