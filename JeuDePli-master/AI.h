#ifndef AI_H
#define AI_H

#include "Player.h"
#include "Card.h"

class AI : public Player {
public : 
	AI(std::string playerName) : Player(std::move(playerName)) {}

	std::unique_ptr<Card> playCard(const Trick& currentTrick, const GameRules* rule) override;
};

#endif
