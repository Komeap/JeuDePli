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
	
	/********************************************************************
	* @brief Permet à un joueur humain de jouer une carte.
	*
	* Demande une carte au joueur humain et donne cete carte à GameEngine.
	********************************************************************
	* @param currentTrick Pli actuellement en cours.
	* @param rules Règles de jeu utilisées pour vérifier la validité du coup.
	*
	* @return std::unique_ptr<Card> Carte choisie par le joueur et retirée de sa main.
	* @return nullptr Ne devrait jamais être retorunée en cas d'utilisation normale.
	*
	* @pre rules != nullptr
	*
	* @post Si une carte valide est jouée :
	* - la carte est retirée de la main du joueur ;
	* - la propriété de la carte est transférée en l'appelant.
	*
	*/
	std::unique_ptr<Card> playCard(const Trick& currentTrick, const GameRules* rules) override;
};
#endif 