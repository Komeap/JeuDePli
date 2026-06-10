#include "Human.h"



std::unique_ptr<Card> Human::playCard(const Trick& currentTrick, const GameRules* rules) {
    if (!currentTrick.getPlayedCards().empty()) {
        std::cout << "The trick is : " << currentTrick.toString() << std::endl;
        std::cout << "The leading suit is : " << currentTrick.getLeadSuit() << std::endl;
    }
    else {
        std::cout << "The trick is empty! You can place the first card!" << std::endl;
    }
    auto& cards = hand.getCards();
    std::cout << "Your hand is : " << hand.toString() << std::endl;
    bool askCard = true;
    while (askCard) {
        std::cout << "You must choose a card ! Gave the index of it (between 0 and the number of cards)." << std::endl;
        int index = _getch() - '0';
        while (index < 0 || index >= cards.size()) {
            std::cout << "Wrong index ! It should be between 0 and the number of cards in your hand." << std::endl;
            index = _getch() - '0';
        }
        if (rules->isValidMove(cards[index], hand, currentTrick)) {
            auto playedCard = std::move(cards[index]);
            cards.erase(cards.begin() + index);
            return playedCard;
        }
    }
    return nullptr;
}