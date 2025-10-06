#include "lexique.hpp"

#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Getter
string Lexique::getNom() const { return this->nom; }
map<string, uint16_t> Lexique::getOccurences() { return this->occurences; }

// Setter
void Lexique::setNom(string nom) { this->nom = nom; }
void Lexique::setOccurences(map<string, uint16_t> occurences) { this->occurences = occurences; }

// Fonctions
void sauvegarderLexique(string texte) // Sauvegarde d'un lexique
{
    ofstream fichier(texte);                   //  Création du fichier
    if (fichier)                               // si l'ouverture a réussi
    {
        // instructions
        fichier.close(); // je referme le fichier
    }
    else
    {
        cerr << "Erreur à l'ouverture" << endl;
    } // sinon
}
