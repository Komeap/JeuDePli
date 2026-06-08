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
		players[index_player]->receiveCard(std::move(deck.drawCard()));
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
// Peut etre a factoriser mais flemme
Player* DameDePiqueRules::determinePlayerToStartTrick(const Hand& hand, const Trick& trick, const std::vector<std::unique_ptr<Player>>& players) {
	Player* startingPlayer = players[0].get();
	if (trick.getPlayedCards().empty()) {
		if (players.size() <= 4) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t w = 1; w < players[i]->getHand().getCards().size(); w++) {
					if (players[i]->getHand().getCards()[w]->getSuit() == "Clubs" && players[i]->getHand().getCards()[w]->getRank() == "2") {
						Player* startingPlayer = players[i].get();
					}
				}
				players[i]->getHand();
			}
		}
		else if (players.size() == 5) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t w = 1; w < players[i]->getHand().getCards().size(); w++) {
					if (players[i]->getHand().getCards()[w]->getSuit() == "Clubs" && players[i]->getHand().getCards()[w]->getRank() == "3") { // Verifie si la carte est dans la main du joueur
						Player* startingPlayer = players[i].get(); // set le joueur qui commence si il a la carte
					}
				}
				players[i]->getHand(); // test le joueur suivant 
			}
		}
		else if (players.size() == 6) {
			for (size_t i = 1; i < players.size(); i++) {
				for (size_t w = 1; w < players[i]->getHand().getCards().size(); w++) {
					if (players[i]->getHand().getCards()[w]->getSuit() == "Clubs" && players[i]->getHand().getCards()[w]->getRank() == "4") {
						Player* startingPlayer = players[i].get();
					}
				}
				players[i]->getHand();
			}
		}
	}else {
		Player* startingPlayer = determineTrickWinner(trick);
	}
	return startingPlayer;
}

std::map<Player*, int> DameDePiqueRules::calculateScores(const Trick& trick, Player* trickwinner){
	int score = 0;
	const auto& playedCards = trick.getPlayedCards();
	for (size_t i = 0; i < playedCards.size(); ++i) {
		if (playedCards[i].second.get()->getSuit() == "Heart") {
			score += 1;
		}
		if (playedCards[i].second.get()->getSuit() == "Spades") {
			score += playedCards[i].second.get()->getPoints();
		}
	}
	scores[trickwinner] += score;
	return scores;
}

bool DameDePiqueRules::isGameOver() const {
	const int SCORE_LIMIT = 100;

	for (const auto& pair : scores) {
		if (pair.second >= SCORE_LIMIT) {
			return true;
		}
	}
	return false;
}