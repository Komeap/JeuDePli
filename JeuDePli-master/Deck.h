#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>
#include <algorithm>
#include <memory>
#include <random>

/// @file Interface de la classe Deck


/********************************************************************************
 * @class Deck
 * @brief Représente un paquet de cartes.
 ********************************************************************************
 * Cette classe gère un ensemble de cartes stockées dans un conteneur dynamique.
 * Elle permet de mélanger le paquet, de piocher des cartes et de vérifier
 * si le deck est vide.
 */
class Deck {
private :
	/// Conteneur interne stockant les cartes du deck
	std::vector<std::unique_ptr<Card>> cards;

	/// Générateur de seed aléatoire
	private:
    /// Conteneur interne stockant les cartes du deck
    std::vector<std::unique_ptr<Card>> vecPtrCartes;

    /// Générateur pseudo-aléatoire initialisé avec une graine matérielle à la volée
    std::default_random_engine objGenerateurAleatoire{ std::random_device{}() };
public :
	Deck() = default;

    /**
     * @brief Destructeur par défaut.
     */
    ~Deck() = default;  

    // --- Ajout pour la Règle des 5 ---
    // On autorise explicitement le déplacement (Move semantics)
    Deck(Deck&&) noexcept = default;
    Deck& operator=(Deck&&) noexcept = default;

    // On interdit explicitement la copie (car on a des unique_ptr)
    Deck(const Deck&) = delete;
    Deck& operator=(const Deck&) = delete;

	/********************************************************************
	 * @brief Mélange aléatoirement les cartes du deck.
	 *
	 * Utilise un générateur pseudo-aléatoire pour réordonner les cartes
	 * du deck de manière uniforme.
	 ********************************************************************
	 * @pre Le deck ne doit pas être vide.
	 *
	 * @return void
	 *
	 * @post L’ordre des cartes dans le deck est modifié aléatoirement.
	 *
	 * @throws std::runtime_error si le deck est vide.
	 */
	void shuffle();
	/********************************************************************
	 * @brief Pioche la carte situé au sommet du deck.
	 *
	 * Retire la dernière carte du conteneur interne et la retourne.
	 ********************************************************************
	 * @pre Le deck ne doit pas être vide.
	 *
	 * @return Card La carte retirée du sommet du deck.
	 *
	 * @post Le deck contient une crate de moins.
	 *
	 * @throws std::runtime_error si le deck est vide.
	 */
	std::unique_ptr<Card> drawCard();

	/****************************************************
	 * @brief Vérifie si le deck est vide.
	 ****************************************************
	 * @return true si le deck ne contient aucune carte.
	 * @return false sinon.
	 *
	 * @post Aucun effet de bord.
	 */
	[[nodiscard]] bool isEmpty() const noexcept { return cards.empty(); }

	void addCard(std::unique_ptr<Card> ptrCarte) {
    cards.push_back(std::move(ptrCarte)); }
};
#endif // DECK_H
