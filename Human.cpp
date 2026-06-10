#include "Human.h"

/// @file Interface de la classe Human

/********************************************************************
* @brief Permet à un joueur humain de jouer une carte.
*
* Demande une carte au joueur humain et donne cete carte à GameEngine.
********************************************************************
* @param currentTrick Pli actuellement en cours.
* @param rules Règles de jeu utilisées pour vérifier la validité du coup.
* 
* @return std::unique_ptr<Card> Carte choisie par le joueur et retirée de sa main.
* @return nullptr Ne devrait jamais être retorunée en cas d'utilisation normale.
* 
* @pre rules != nullptr
* 
* @post Si une carte valide est jouée :
* - la carte est retirée de la main du joueur ;
* - la propriété de la carte est transférée en l'appelant.
*
*/
std::unique_ptr<Card> Human::playCard(const Trick& currentTrick, const GameRules* rules) {
    // Renvoit une exception si les règles sont null.
    if (rules == nullptr) {
        throw std::runtime_error("Hand::playCard - empty rules");
    }
    // Si le pli n'est pas vide et il y a une leading suit
    if (!currentTrick.getPlayedCards().empty()) {
        std::cout << "The trick is : " << currentTrick.toString() << std::endl;
        std::cout << "The leading suit is : " << currentTrick.getLeadSuit() << std::endl;
    }
    // sinon il n'y en a pas
    else {
        std::cout << "The trick is empty! You can place the first card!" << std::endl;
    }
    // On prends et on affiche les cartes de la main du joueur. 
    auto& cards = hand.getCards();
    std::cout << "Your hand is : " << hand.toString() << std::endl;
    bool askCard = true;
    // Tant que la carte n'est pas valide, on redemande au joueur de choisir.
    while (askCard) {
        std::cout << "You must choose a card ! Gave the index of it (between 0 and the number of cards)." << std::endl;
        int index = _getch() - '0';
        while (index < 0 || index >= cards.size()) {
            std::cout << "Wrong index ! It should be between 0 and the number of cards in your hand." << std::endl;
            index = _getch() - '0';
        }
        // Si elle est valide, on retire la carte de la main du joueur et on la retourne au moteur du jeu.
        if (rules->isValidMove(cards[index], hand, currentTrick)) {
            auto playedCard = std::move(cards[index]);
            cards.erase(cards.begin() + index);
            return playedCard;
        }
    }
    return nullptr;
}