#include "Hand.h"
#include "Trick.h"
#include "GameRules.h"

class Player {
protected:
    std::string name;
    Hand hand;

public:
    Player(std::string playerName) : name(std::move(playerName)) {}
    virtual ~Player() = default; // Destructeur virtuel crucial pour le polymorphisme

    // Méthode virtuelle pure : chaque type de joueur joue différemment
    virtual Card playCard(const Trick& currentTrick, const GameRules* rules) = 0;
    
    void receiveCard(const Card& card) { hand.addCard(card); }
    [[nodiscard]] std::string getName() const { return name; }
};