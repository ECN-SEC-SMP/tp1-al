#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <iostream>
#include <cstdint>

using namespace std;

// Création de la classe
class Lexique {

private:
    string nom;
    map<string, uint16_t> occurences;
public:
    // Constructeurs
    Lexique(string nom, string nom_fichier);

    // Accesseurs
    string getNom() const;
    const map<string, uint16_t>& getOccurences() const;

    // Mutateurs
    void setNom(string nom);
    void setOccurences(map<string, uint16_t> occurences);

    // Fonctions
    void sauvegarderLexique(string texte);
    void supprimerMot(string nom);
    void addWordUsage(string mot, uint16_t occurences);
    uint16_t nombreDeMots();
    uint16_t getOccurencesFromWord(string mot);

    // Operateurs
    Lexique& operator+=(const Lexique& lex);
};

std::ostream& operator<<(std::ostream& os, const Lexique& lex);