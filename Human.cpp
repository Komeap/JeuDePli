#include "Human.h"
#include <iostream>

std::unique_ptr<Card> Human::playCard(const Trick& currentTrick, const GameRules* rules) {
    std::cout << "Your hand is : " << hand.toString() << std::endl;
    if (!currentTrick.getPlayedCards().empty()) {
        std::cout << "The trick is : " << currentTrick.toString() << std::endl;
        std::cout << "The leading suit is : " << currentTrick.getLeadSuit() << std::endl;
    }
    else {
        std::cout << "The trick is empty! You can place the first card!" << std::endl;
    }
    const auto& cards = hand.getCards();

}