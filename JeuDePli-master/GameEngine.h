#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Player.h"
#include "Deck.h"
#include "GameRules.h"

class GameEngine {
private : 
	std::vector<std::unique_ptr<Player>> players;
	std::unique_ptr<GameRules> rules;
	Deck deck;

public :
	GameEngine() = default; //Déclaration default explicit du constructeur 
	~GameEngine() = default; //Déclaration default explicit du destructeur 

	void setupGame(std::unique_ptr<GameRules> selectedRules);
	void playTrick();
	void playMatch();
	void displayResults() const;
};
#endif

