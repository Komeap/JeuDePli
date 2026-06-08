#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include "Trick.h"
#include "GameRules.h"

#include <iostream>
#include <memory>
#include <conio.h>

class Human : public Player {
public :
	Human(std::string playerName) : Player(std::move(playerName)) {}

	std::unique_ptr<Card> playCard(const Trick& currentTrick, const GameRules* rules) override;
};
#endif 