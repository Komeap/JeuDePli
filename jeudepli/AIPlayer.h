#include "Player.h"
#include "Card.h"

class AIPlayer : public Player {
public:
    AIPlayer(std::string playerName) : Player(std::move(playerName)) {}
    
    Card playCard(const Trick& currentTrick, const GameRules* rules) override;
};