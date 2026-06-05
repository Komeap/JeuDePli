#include "Hand.h"

/// @file Implémentation de la classe Hand


void Hand::removeCard(const Card* card) {
    auto it = std::find_if(
        cards.begin(),
        cards.end(),
        [card](const std::unique_ptr<Card>& ptr)
        {
            return ptr.get() == card;
        });

    if (it != cards.end())
    {
        cards.erase(it);
    }
}

std::unique_ptr<Card> Hand::playCard(size_t index)
{
    auto card = std::move(cards[index]);
    cards.erase(cards.begin() + index);
    return card;
}

std::string Hand::toString() const {
    std::string result;

    for (const auto& card : cards) {
        result += card->toString() + "\n";
    }

    return result;
}

