#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <vector>

// ON VA TRANSFO LES CARTES en unique ptr
class Hand {
private: 
	std::vector<Card> cards;

public :
	Hand() = default; //Déclaration default explicit du constructeur 
	~Hand() = default; //Déclaration default explicit du destructeur 

	void addCard(const Card& card);
	void removeCard(const Card& card);

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] std::vector<Card> getCards() const { return cards; }

};
#endif
