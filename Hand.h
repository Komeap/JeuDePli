#ifndef HAND_H
#define HAND_H

#include "Card.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

class Hand {
private:
	std::vector<std::unique_ptr<Card>> cards;

public:
	Hand() = default; //Déclaration default explicit du constructeur 
	~Hand() = default; //Déclaration default explicit du destructeur 

	void addCard(std::unique_ptr<Card> card) { cards.push_back(std::move(card)); }
	void removeCard(const Card* card);
	std::unique_ptr<Card> playCard(size_t index);


	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] const std::vector<std::unique_ptr<Card>>& getCards() const { return cards; }
	[[nodiscard]] std::string toString() const;

};
#endif
