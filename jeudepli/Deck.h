#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() = default;
    ~Deck() = default;

    void shuffle();
    Card drawCard();
    [[nodiscard]] bool isEmpty() const;
};