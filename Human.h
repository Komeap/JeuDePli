#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include "Trick.h"
#include "GameRules.h"

class Human : public Player {
public :
	Human(std::string playerName) : Player(std::move(playerName)) {}

	Card playCard(const Trick& currentTrick, const GameRules* rules) override;
};
#endif 