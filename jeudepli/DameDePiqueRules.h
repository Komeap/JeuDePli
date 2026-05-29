#include "GameRules.h"
#include "Deck.h"
#include "Player.h"
#include "Trick.h"
#include <map>
#include <vector>

class DameDePiqueRules : public GameRules {
public:
    void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) override;
    [[nodiscard]] bool isValidMove(const Card& card, const Hand& hand, const Trick& trick) const override;
    [[nodiscard]] Player* determineTrickWinner(const Trick& trick) const override;
    [[nodiscard]] std::map<Player*, int> calculateScores(const std::vector<std::unique_ptr<Player>>& players) const override;
    [[nodiscard]] bool isGameOver() const override;
};