#include <vector>
#include "Player.h"
#include "Deck.h"
#include "GameRules.h"

class GameEngine {
private:
    std::vector<std::unique_ptr<Player>> players; // Possession exclusive des joueurs
    std::unique_ptr<GameRules> rules;             // Possession exclusive des règles
    Deck deck;

public:
    GameEngine() = default;
    ~GameEngine() = default;

    // setupGame pourrait prendre un Enum GameType ou directement un std::unique_ptr<GameRules>
    void setupGame(std::unique_ptr<GameRules> selectedRules);
    void playTrick();
    void playMatch();
    void displayResults() const;
};