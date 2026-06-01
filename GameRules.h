#ifndef GAMERULES_H
#define GAMERULES_H

#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include "Trick.h"
#include "Card.h"

#include <vector>
#include <map>

class GameRules {
public:
    virtual ~GameRules() = default;

    
    virtual void distributeCards(Deck& deck, const std::vector<std::unique_ptr<Player>>& players) = 0;
    
    // nodiscard permet d'indiquer au compilateur qu'on ne doit pas ignorer le retour.
    [[nodiscard]] virtual bool isValidMove(const Card& card, const Hand& hand, const Trick& trick) const = 0;
    [[nodiscard]] virtual Player* determineTrickWinner(const Trick& trick) const = 0;
    [[nodiscard]] virtual std::map<Player*, int> calculateScores(const std::vector<std::unique_ptr<Player>>& players) const = 0;
    [[nodiscard]] virtual bool isGameOver() const = 0;
};

#endif