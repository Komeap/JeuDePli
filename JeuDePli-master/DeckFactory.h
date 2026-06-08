#ifndef DECKFACTORY_HPP
#define DECKFACTORY_HPP

#include "Deck.h"
#include <string>

class DeckFactory {
public:
    DeckFactory() = default;
    ~DeckFactory() = default;

    // Utilisation d'une méthode statique car la Factory n'a pas besoin d'état interne
    static Deck construireDepuisJson(const std::string& strCheminFichier);
};

#endif // DECKFACTORY_HPP