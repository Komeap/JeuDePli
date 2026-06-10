#ifndef DAMEDEPIQUERULES_H
#define DAMEDEPIQUERULES_H

#include "GameRules.h"
#include "Deck.h"
#include "Player.h"
#include "Trick.h"
#include <map>
#include <vector>

class DameDePiqueRules : public GameRules {

public:
	DameDePiqueRules(const int nbMax, const int nbMin) : GameRules(nbMax, nbMin) {}; 

	/********************************************************************
	 * @brief Initialise les scores des joueurs.
	 *
	 * Vide la map des scores et l'initialise à 0 pour chaque joueur
	 * afin d'éviter les problèmes lors de parties consécutives.
	 ********************************************************************
	 * @param players La liste des joueurs participant à la partie.
	 * * @return void
	 */
	void initScores(const std::vector<std::unique_ptr<Player>>& players) {
		scores.clear(); // Pour eviter les problemes si on fait plusieur partie d'affiler
		for (size_t i = 0; i < players.size(); i++) {
			scores[players[i].get()] = 0;
		}
	};

	/********************************************************************
	 * @brief Adapte le paquet de cartes.
	 *
	 * Modifie le paquet actuel en fonction du nombre de joueurs présents
	 * dans la partie.
	 ********************************************************************
	 * @param deck Le paquet de base contenant les cartes.
	 * @param players La liste des joueurs dans la partie.
	 * * @return void
	 * * @post Le paquet de cartes passé en paramètre est modifié.
	 */
	void modifyDeck(std::vector<std::unique_ptr<Card>> deck, const std::vector<std::unique_ptr<Player>>& players);

	/********************************************************************
	 * @brief Distribue les cartes aux joueurs.
	 *
	 * Fonction qui attribue les cartes du deck à chaque joueur de
	 * la partie.
	 ********************************************************************
	 * @param deck Le deck contenant les cartes à distribuer.
	 * @param players La liste des joueurs.
	 * * @return void
	 */
	void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) override;

	/********************************************************************
	 * @brief Détermine le joueur qui doit entamer le pli.
	 *
	 * S'il s'agit du premier pli, le joueur possédant le 2 de Trèfle
	 * commence. Sinon, c'est le gagnant du pli précédent.
	 ********************************************************************
	 * @param hand La main du joueur évalué.
	 * @param trick Le pli actuel.
	 * @param players La liste des joueurs de la partie.
	 * * @return Player* Un pointeur vers le joueur concerné.
	 */
	Player* determinePlayerToStartTrick(const Hand& hand, const Trick& trick, const std::vector<std::unique_ptr<Player>>& players);

	/********************************************************************
	 * @brief Vérifie si le coup joué est valide.
	 *
	 * Contrôle le respect de la couleur demandée et des contraintes
	 * spécifiques pour déterminer si la carte peut être posée.
	 ********************************************************************
	 * @param carte La carte à évaluer.
	 * @param main La main du joueur.
	 * @param pli Le pli en cours.
	 * * @return bool True si la carte peut être jouée.
	 * * @note L'attribut [[nodiscard]] indique au compilateur que la valeur
	 * de retour ne doit pas être ignorée.
	 */
	[[nodiscard]] bool isValidMove(std::unique_ptr<Card> card, const Hand& hand, const Trick& trick) const;

	 /********************************************************************
	  * @brief Détermine le gagnant du pli en cours.
	  *
	  * Évalue la carte gagnante parmi celles jouées sur le pli et
	  * identifie le joueur associé à cette carte.
	  ********************************************************************
	  * @param trick Le pli en cours à évaluer.
	  * * @return Player* Un pointeur vers le joueur gagnant.
	  */
	[[nodiscard]] Player* determineTrickWinner(const Trick& trick) const override;

	/********************************************************************
	 * @brief Calcule le score de chaque joueur.
	 *
	 * Met à jour et retourne les points obtenus en fonction du pli joué.
	 ********************************************************************
	 * @param trick Le pli venant d'être joué.
	 * @param trickwinner Le joueur ayant remporté le pli.
	 * * @return std::map<Player*, int> Une map associant chaque joueur à son score.
	 * * @note Peut-être à mettre en virtual.
	 */
	[[nodiscard]] std::map<Player*, int> calculateScores(const Trick& trick, Player* trickwinner);

	/********************************************************************
	 * @brief Vérifie si la partie est terminée.
	 *
	 * Contrôle si les conditions requises pour la fin de la partie sont
	 * remplies.
	 ********************************************************************
	 * @return bool True si les conditions de fin de partie sont remplies.
	 */
	[[nodiscard]] bool isGameOver() const override;
};
#endif