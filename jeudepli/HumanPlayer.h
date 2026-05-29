#include "Player.h"
#include "Trick.h"
#include "GameRules.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string playerName) : Player(std::move(playerName)) {}
    
    Card playCard(const Trick& currentTrick, const GameRules* rules) override;
};


