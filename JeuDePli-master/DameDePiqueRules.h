#ifndef DAMEDEPIQUERULES_H
#define DAMEDEPIQUERULES_H

#include "GameRules.h"
#include "Deck.h"
#include "Player.h"
#include "Trick.h"

#include <map>
#include <vector>

class DameDePiqueRules : public GameRules {
public :
	void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) override;

	// nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
	[[nodiscard]] bool isValidMove(std::unique_ptr<Card> card, const Hand& hand, const Trick& trick) const override;
	[[nodiscard]] Player* determineTrickWinner(const Trick& trick) const override;
	[[nodiscard]] std::map<Player*, int> calculateScores(const std::vector<std::unique_ptr<Player>>& players) const override;
	[[nodiscard]] bool isGameOver() const override;
};
#endif
