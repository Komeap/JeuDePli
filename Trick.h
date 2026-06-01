#ifndef TRICK_H
#define TRICK_H

#include "Player.h"
#include "Card.h"

#include <vector>

class Trick {
private :
	// Vecteur contenant l’historique des cartes jouées
	// Chaque élément est une paire (Player*, Card)
	std::vector<std::pair<Player*, Card>> playedCards;

public:
	Trick() = default;
	~Trick() = default;

	void addCard(Player* player, const Card& card);

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] Suit getLeadSuit() const;
	[[nodiscard]] const std::vector<std::pair<Player*, Card>>& getPlayedCards() const { return playedCards; }

};
#endif
