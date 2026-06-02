#ifndef CARD_H
#define CARD_H

#include "Suit.h"
#include "Rank.h"

class Card {
private :
	std::string suit;
	std::string rank;
	int points;
public :
	Card(std::string s, std::string r, int p = 0) : suit(s), rank(r), points(p) {}
	~Card() = default; //Déclaration default explicit du destructeur 

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] std::string getSuit() const { return suit; }
	[[nodiscard]] std::string getRank() const { return rank; }
	[[nodiscard]] int getPoints() const { return points; }
	[[nodiscard]] std::string toString() const;
};
#endif
