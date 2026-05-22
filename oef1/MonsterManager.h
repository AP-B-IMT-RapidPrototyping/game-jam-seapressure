#pragma once


#ifdef _MSVC_LANG
static_assert(_MSVC_LANG >= 201703L, "C++17 required");
#else
static_assert(__cplusplus >= 201703L, "C++17 required");
#endif


//-----------------------------------------------------
// Include Files
//-----------------------------------------------------

#include "Monster.h"
#include "Warning.h"

#include "Singleton.h"
#include <vector>

namespace game {
    //-----------------------------------------------------
    // MonsterManager Class
    //-----------------------------------------------------
    class MonsterManager final : public Singleton<MonsterManager> {
    public:
        MonsterManager(); // Constructor
        ~MonsterManager() override; // Destructor

        //-------------------------------------------------
        // Member functions
        //-------------------------------------------------


        void Update(const Vector2 &playerPos);

        void Draw() const;

        void SpawnMonster();
        void SpawnMonsterBatch(int amount);

        bool isPlayerHit{false};

    private:
        //-------------------------------------------------
        // Private member functions
        //-------------------------------------------------

        //-------------------------------------------------
        // Datamembers
        //-------------------------------------------------
        friend class Singleton<MonsterManager>;
        inline static Texture2D tMonster;

        inline static Texture2D tWarning;

        std::vector<Monster *> monsters;
        std::vector<Warning *> warnings;
    };
}
