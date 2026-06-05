#include "Deck.h"

/// @file Implémentation de la classe Deck


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
void Deck::shuffle() {
	if (cards.empty()) {
		throw std::runtime_error("Deck::shuffle - empty deck");
	}

	std::ranges::shuffle(cards, rng_);
}


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
std::unique_ptr<Card> Deck::drawCard() {
    if (cards.empty()) {
        throw std::runtime_error("Deck::drawCard - empty deck");
    }

    std::unique_ptr<Card> card = std::move(cards.back());
    cards.pop_back();
    return card;
}
