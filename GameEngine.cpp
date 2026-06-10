#include "GameEngine.h"

void GameEngine::setupGame(std::unique_ptr<GameRules> selectedRules) {
    if (selectedRules == nullptr) {
        throw std::runtime_error("GameEngine::setupGame - there is no rules");
    }
    std::cout << "You must choose the number of human player ! You must choose a number between " << selectedRules->getNbPlayerMin() << " and " << selectedRules->getNbPlayerMax() << "." << std::endl;
    int nbPlayer = _getch() - '0';
    while (nbPlayer < selectedRules->getNbPlayerMin() || nbPlayer > selectedRules->getNbPlayerMax()) {
        std::cout << "Wrong number ! You must choose a number between " << selectedRules->getNbPlayerMin() << " and " << selectedRules->getNbPlayerMax() << "." << std::endl;
        nbPlayer = _getch() - '0';
    }
    while (!selectedRules->isGameOver()) {

    }
}