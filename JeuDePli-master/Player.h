#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Trick.h"
#include "GameRules.h"

#include <iostream>

class Player {
protected : 
	std::string name;
	Hand hand;

public : 
	Player(std::string playerName) : name(std::move(playerName)) {}
	virtual ~Player() = default;

	virtual std::unique_ptr<Card> playCard(const Trick& currentTrick, const GameRules* rules) = 0;

	void receiveCard(std::unique_ptr<Card> card) { hand.addCard(card); }

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] std::string getName() const { return name; }

};
#endif
