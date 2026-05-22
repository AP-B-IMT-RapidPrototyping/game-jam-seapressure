#include "Game.h"

using namespace game;

    int main() {
        Game game;
        while (!Game::ShouldClose()) {
            game.Update();
            game.Draw();
        }

        return 0;
    }

