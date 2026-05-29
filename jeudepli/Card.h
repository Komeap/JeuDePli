#include "Suit.h"
#include "Rank.h"

class Card {
private:
    Suit suit;
    Rank rank;
    int points;

public:
    Card(Suit s, Rank r, int p = 0) : suit(s), rank(r), points(p) {}
    ~Card() = default;

    [[nodiscard]] Suit getSuit() const { return suit; }
    [[nodiscard]] Rank getRank() const { return rank; }
    [[nodiscard]] int getPoints() const { return points; }
    [[nodiscard]] std::string toString() const; // À implémenter
};

