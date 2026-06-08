#ifndef DAMEDEPIQUERULES_H
#define DAMEDEPIQUERULES_H

#include "GameRules.h"
#include "Deck.h"
#include "Player.h"
#include "Trick.h"
#include <map>
#include <vector>

class DameDePiqueRules : public GameRules {
protected :
	std::map<Player*, int> scores;
public:

	void initScores(const std::vector<std::unique_ptr<Player>>& players) {
		scores.clear(); // Pour eviter les problemes si on fait plusieur partie d'affiler
		for (size_t i = 0; i < players.size(); i++) {
			scores[players[i].get()] = 0;
		}
	};

	// Adapte le paquet de cartes en fonction du nombre de joueurs dans la partie.
	// Prend en paramètre le paquet de base et la liste des joueurs.
	// Retourne rien, mais modifie le paquet actuel
	void modifyDeck(std::vector<std::unique_ptr<Card>> deck, const std::vector<std::unique_ptr<Player>>& players);

	// Distribue les cartes aux joueurs.
	// Fonction sans valeur de retour qui attribue les cartes à chaque joueur de la partie.
	void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) override;

	// Détermine le joueur qui doit entamer le pli.
	// S'il s'agit du premier pli, le joueur possédant le 2 de Trèfle commence.
	// Sinon, c'est le gagnant du pli précédent.
	// Retourne un pointeur vers le joueur concerné.
	Player* determinePlayerToStartTrick(const Hand& hand, const Trick& trick, const std::vector<std::unique_ptr<Player>>& players);

	// L'attribut [[nodiscard]] indique au compilateur que la valeur de retour ne doit pas être ignorée.

	// Vérifie si le coup joué est valide (respect de la couleur demandée, contraintes spécifiques).
	// Prend en paramètre la carte à évaluer, la main du joueur et le pli en cours.
	// Retourne true si la carte peut être jouée.

	// Détermine le gagnant du pli en cours.
	// Évalue la carte gagnante et identifie le joueur associé à cette carte.
	// Retourne un pointeur vers le joueur gagnant.
	[[nodiscard]] Player* determineTrickWinner(const Trick& trick) const override;

	// Calcule le score de chaque joueur.
	// Retourne une map associant chaque joueur à son score (entier).
	// PEut etre mettre en virtual 
	[[nodiscard]] std::map<Player*, int> calculateScores(const Trick& trick, Player* trickwinner);

	// Vérifie si la partie est terminée.
	// Retourne true si les conditions de fin de partie sont remplies.
	[[nodiscard]] bool isGameOver() const override;
};

#endif