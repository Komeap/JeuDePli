#include "DeckFactory.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Inclusion de la bibliothèque nlohmann/json
#include <nlohmann/json.hpp> 

using json = nlohmann::json;

Deck DeckFactory::construireDepuisJson(const std::string& strCheminFichier) {
    Deck objNouveauDeck;
    
    // Ouverture du fichier texte
    std::ifstream objFluxFichier(strCheminFichier);
    if (!objFluxFichier.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier " + strCheminFichier);
    }

    try {
        // Parsing du JSON
        json objDonneesJson;
        objFluxFichier >> objDonneesJson;

        // Vérification de la présence de la clé "cartes"
        if (objDonneesJson.contains("cartes") && objDonneesJson["cartes"].is_array()) {
            
            // Parcours du tableau de cartes dans le JSON
            for (const auto& objCarteJson : objDonneesJson["cartes"]) {
                
                // Extraction des attributs avec valeurs par défaut si manquants
                std::string strFamille = objCarteJson.value("famille", "Inconnue");
                std::string strValeur = objCarteJson.value("valeur", "Inconnue");
                int intPoints = objCarteJson.value("points", 0);

                // Création du pointeur intelligent pour la nouvelle carte
                std::unique_ptr<Card> ptrNouvelleCarte = std::make_unique<Card>(strFamille, strValeur, intPoints);

                // Ajout de la carte au deck (nécessite l'ajout de cette méthode dans Deck.h)
                objNouveauDeck.addCard(std::move(ptrNouvelleCarte));
            }
        } else {
            throw std::runtime_error("Erreur : Format JSON invalide, cle 'cartes' manquante.");
        }
    } catch (const json::parse_error& objErreur) {
        throw std::runtime_error("Erreur de parsing JSON : " + std::string(objErreur.what()));
    }

    return objNouveauDeck;
}