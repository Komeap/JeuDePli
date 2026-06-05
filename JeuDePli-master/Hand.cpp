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