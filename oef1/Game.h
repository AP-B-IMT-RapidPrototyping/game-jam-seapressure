//
// Created by marsd on 13/03/2026.
//

#ifndef OEF1_GAME_H
#define OEF1_GAME_H

#include <vector>

#include "Monster.h"
#include "Player.h"
#include "MonsterManager.h"

namespace game {
    class Game final{
    public:
        Game();
        ~Game();

        Game(const Game& other)					= default;
        Game(Game&& other) noexcept				= default;
        Game& operator=(const Game& other)		= default;
        Game& operator=(Game&& other)	noexcept	= default;

        void Update();
        void Draw() const;
        bool isGameOver=false;
        static bool ShouldClose();

    private:
        // void SpawnMonster();


        int width;
        int height;
        int fps;
        std::vector<Monster*> monsters;
        Player* player;
        MonsterManager* monsterManager;
        inline static Texture2D tMonster;
        inline static Texture2D tPlayer;
        Color seaShade = {102, 191, 255, 255 };

    };
} // game

#endif //OEF1_GAME_H