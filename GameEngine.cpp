#include "GameEngine.h"

void GameEngine::setupGame(std::unique_ptr<GameRules> selectedRules) {
    if (selectedRules == nullptr) {
        throw std::runtime_error("GameEngine::setupGame - there is no rules");
    }

}