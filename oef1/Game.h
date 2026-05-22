//
// Created by marsd on 13/03/2026.
//
#pragma once

#ifndef OEF1_GAME_H
#define OEF1_GAME_H

#include <memory>
#include <vector>

#include "Monster.h"
#include "Player.h"
#include "MonsterManager.h"
#include "Gate.h"

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
        int level{-1};
        float timer{0.f};
        std::vector<Monster*> monsters;
        Player* player;
        MonsterManager* monsterManager;
        inline static Texture2D tMonster;
        inline static Texture2D tPlayer;
        Color bgc = {102, 191, 255, 255 };
        Color bgcNext() const;
        Color bgcGate() const;

        int EnemyAmount() const {return 3+level;}
        Gate* gate;

        bool isLvcleared{false};




    };
} // game

#endif //OEF1_GAME_H