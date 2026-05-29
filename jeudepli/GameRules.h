#include "Deck.h"
#include <vector>
#include "Player.h"
#include "Hand.h"
#include "Trick.h"
#include "Card.h"
#include <map>

class GameRules {
public:
    virtual ~GameRules() = default;

    // Méthodes virtuelles pures définissant le contrat pour n'importe quel jeu de plis
    virtual void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) = 0;
    [[nodiscard]] virtual bool isValidMove(const Card& card, const Hand& hand, const Trick& trick) const = 0;
    [[nodiscard]] virtual Player* determineTrickWinner(const Trick& trick) const = 0;
    [[nodiscard]] virtual std::map<Player*, int> calculateScores(const std::vector<std::unique_ptr<Player>>& players) const = 0;
    [[nodiscard]] virtual bool isGameOver() const = 0;
};