#ifndef CARD_H
#define CARD_H

#include "Suit.h"
#include "Rank.h"

class Card {
private :
	Suit suit;
	Rank rank;
	int points;
public :
	Card(Suit s, Rank r, int p = 0): suit(s), rank(r), points(p) {}
	~Card() = default; //Déclaration default explicit du destructeur 

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] Suit getSuit() const { return suit; }
	[[nodiscard]] Rank getRank() const { return rank; }
	[[nodiscard]] int getPoints() const { return points; }
	[[nodiscard]] std::string toString() const;
};
#endif
