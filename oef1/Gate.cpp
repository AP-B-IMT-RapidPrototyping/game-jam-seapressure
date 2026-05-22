//
// Created by hares on 22/05/2026.
//

#include "Gate.h"

namespace game {

    void Gate::switchPos() {
        const int maxX{GetScreenWidth() - static_cast<int>(Radius)};
        const int maxY{GetScreenHeight() - static_cast<int>(Radius)};

        Vector2 spawnPos;
        do {
            spawnPos = {
                static_cast<float>(GetRandomValue(0, maxX - 1)),
                static_cast<float>(GetRandomValue(0, maxY - 1))
            };
        }
        while (std::abs(spawnPos.x-position.x) >=300.f || std::abs(spawnPos.y-position.y) >=300.f );

        position=spawnPos;



        }

    void Gate::Draw(const Color &outer) const {
        Color inner{
            static_cast<unsigned char>(std::max(outer.r -100, 0 )), // put in clamp to ensure the int wouldn't cycle back up to 255 when subtracting past 0
            static_cast<unsigned char>(std::max(outer.g -100, 0)),
            static_cast<unsigned char>(std::max(outer.b -100, 0)), 255};

        DrawCircleGradient(position.x,position.y,Radius,inner,outer);
    }

}

