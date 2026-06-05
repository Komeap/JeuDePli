#include "Trick.h"

std::string Trick::getLeadSuit() const { 
    if (playedCards.empty()) {
        throw std::runtime_error("Le pli est vide");
    }
    return playedCards.front().second->getSuit();
}

std::string Trick::toString() const {
    std::string result;

    for (const auto& entry : playedCards) {
        result += entry.second->toString() + "\n";
    }

    return result;
}