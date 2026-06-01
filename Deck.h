#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>

class Deck {
private :
	std::vector<Card> cards;

public :
	Deck() = default; //Déclaration default explicit du constructeur 
	~Deck() = default; //Déclaration default explicit du destructeur 

	void shuffle();
	Card drawCard();

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] bool isEmpty() const;
};
#endif
