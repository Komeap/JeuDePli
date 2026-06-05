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

Player* DameDePiqueRules::determineTrickWinner(const Trick& trick) const {
	Card winning_card = *(trick.getPlayedCards().front().second);
	for (int _; _ < trick.getPlayedCards().size() ; _++) {
		
	}
}