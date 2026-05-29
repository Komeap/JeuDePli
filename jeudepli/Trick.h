#include "Player.h"
#include "Card.h"
#include <vector>

class Trick {
private:
    std::vector<std::pair<Player*, Card>> playedCards;

public:
    Trick() = default;
    ~Trick() = default;

    void addCard(Player* player, const Card& card);
    [[nodiscard]] Suit getLeadSuit() const;
    [[nodiscard]] const std::vector<std::pair<Player*, Card>>& getPlayedCards() const { return playedCards; }
};