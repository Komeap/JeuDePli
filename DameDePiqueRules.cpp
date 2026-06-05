#include "DameDePiqueRules.h"

//Suppresion de certaines carte celon le nombre de joueurs, celon des regles trouver (personne a les meme)
// SI 5 ou si joueur, faut modifier la carte de début. Gerer dans determinePlayerToStart()
void DameDePiqueRules::modifyDeck(std::vector<std::unique_ptr<Card>> deck, const std::vector<std::unique_ptr<Player>>& players) {
	int nb_joueur = players.size();
	
	if (nb_joueur == 3) {
		std::erase(deck, Card("Carreau", "2"));
	}
	if (nb_joueur == 5) {
		std::erase(deck, Card("Carreau", "2"));
		std::erase(deck, Card("Trefle", "2"));
	}
	if (nb_joueur == 6) {
		std::erase(deck, Card("Carreau", "2"));
		std::erase(deck, Card("Trefle", "2"));
		std::erase(deck, Card("Carreau", "3"));
		std::erase(deck, Card("Trefle", "3"));
	}
}

// Donne les cartes une par une a chaque joueur, jusqu'a la fin du paquet 
// puisque on a modifier le paquet avant pour qu'il y ait le bon nombre de carte
void DameDePiqueRules::distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players){
	deck.shuffle();
	int index_player = 1;
	while (!deck.isEmpty()) {
		if (index_player == players.size() + 1) { index_player = 1;}
		players[index_player]->receiveCard(deck.drawCard());
		index_player += 1;
	}
}

// Donne le joueur qui a gagner le pli
Player* DameDePiqueRules::determineTrickWinner(const Trick& trick) const {
	// On met le winner au premier joueur/carte et on prend la couleur demander
	std::string ledSuit = trick.getPlayedCards().front().second->getSuit();

	Player* winningPlayer = trick.getPlayedCards().front().first;
	const Card* winningCard = trick.getPlayedCards().front().second.get();

	// On parcours les cartes
	for (size_t i = 1; i < trick.getPlayedCards().size(); ++i) {
		const auto& [currentPlayer, currentCardPtr] = trick.getPlayedCards()[i];

		// SI la carte existe bien, au cas ou 
		if (currentCardPtr) {
			const Card* currentCard = currentCardPtr.get();
			// ON verifie la condition de victoire, couelur demandé et plus grand
			if (currentCard->getSuit() == ledSuit) {
				if (currentCard->getRank() > winningCard->getRank()) {
					winningCard = currentCard;
					winningPlayer = currentPlayer;
				}
			}
		}
	}
	return winningPlayer;
}

// Determine le joueur qui commence a jouer
// Le gagnant du dernier pli ou le joueur avec la bonne carte au premier tours
Player* DameDePiqueRules::determinePlayerToStartTrick(const Hand& hand, const Trick& trick, const std::vector<std::unique_ptr<Player>>& players) {
	if (trick.getPlayedCards().empty()) {
		if (players.size() <= 4) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t vrejvpiq = 1; vrejvpiq < players[i]->getHand().getCards().size(); vrejvpiq++) {
					if (players[i]->getHand().getCards()[vrejvpiq]->getSuit() == "Trefle" && players[i]->getHand().getCards()[vrejvpiq]->getRank() == "2") {
						Player* startingPlayer = players[i].get();
					}
				}
				players[i]->getHand();
			}
		}
		else if (players.size() == 5) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t vrejvpiq = 1; vrejvpiq < players[i]->getHand().getCards().size(); vrejvpiq++) {
					if (players[i]->getHand().getCards()[vrejvpiq]->getSuit() == "Trefle" && players[i]->getHand().getCards()[vrejvpiq]->getRank() == "3") {
						Player* startingPlayer = players[i].get();
					}
				}
				players[i]->getHand();
			}
		}
		else if (players.size() == 6) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t vrejvpiq = 1; vrejvpiq < players[i]->getHand().getCards().size(); vrejvpiq++) {
					if (players[i]->getHand().getCards()[vrejvpiq]->getSuit() == "Trefle" && players[i]->getHand().getCards()[vrejvpiq]->getRank() == "4") {
						Player* startingPlayer = players[i].get();
					}
				}
				players[i]->getHand();
			}
		}
	}
	else {
		Player* startingPlayer = determineTrickWinner(trick);
	}
	
}