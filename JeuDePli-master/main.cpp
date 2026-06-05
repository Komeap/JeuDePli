#include <iostream>
#include <string>
#include <memory>
#include <exception>

#include "DeckFactory.h"
#include "Deck.h"
#include "Card.h"

int main() {
    // Définition du chemin vers le fichier JSON de test
    // Assure-toi que le fichier se trouve dans le répertoire d'exécution de ton programme
    std::string strCheminFichier = "dame_de_pique.json";

    std::cout << "=== Demarrage du test d'importation ===" << std::endl;
    std::cout << "Tentative de lecture du fichier : " << strCheminFichier << std::endl;

    try {
        // Utilisation de la factory pour instancier et remplir le deck
        Deck objDeckTest = DeckFactory::construireDepuisJson(strCheminFichier);
        
        std::cout << "\nImportation reussie ! Affichage du contenu du deck :" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

        int intCompteur = 1;
        
        // On vérifie le contenu en piochant toutes les cartes jusqu'à vider le deck
        while (!objDeckTest.isEmpty()) {
            std::unique_ptr<Card> ptrCartePiochee = objDeckTest.drawCard();
            
            // Utilisation des getters de ta classe Card pour l'affichage
            std::cout << "Carte " << intCompteur << " : " 
                      << ptrCartePiochee->getRank() << " de " 
                      << ptrCartePiochee->getSuit() 
                      << " (Points : " << ptrCartePiochee->getPoints() << ")" << std::endl;
            
            intCompteur++;
        }
        
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Test termine avec succes. Le deck est maintenant vide." << std::endl;

    } catch (const std::exception& objErreur) {
        // Capture et affichage des erreurs (ex: fichier introuvable, JSON invalide)
        std::cerr << "\n[ERREUR FATALE] : " << objErreur.what() << std::endl;
        return 1; // Code de retour indiquant un échec
    }

    return 0; // Code de retour standard pour un succès
}