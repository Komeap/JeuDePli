#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Card.h"

class AI : public Player {
public : 
	AI(std::string playerName) : Player(std::move(playerName)) {}

	Card playCard(const Trick& currentTrick, const GameRules* rule) override;
};

#endif
