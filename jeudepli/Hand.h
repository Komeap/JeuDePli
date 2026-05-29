#include <vector>
#include "Card.h"

class Hand {
private:
    std::vector<Card> cards;

public:
    Hand() = default;
    ~Hand() = default;

    void addCard(const Card& card);
    void removeCard(const Card& card);
    [[nodiscard]] std::vector<Card> getCards() const { return cards; }
};