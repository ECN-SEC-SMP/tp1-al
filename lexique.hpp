#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <iostream>
#include <cstdint>

using namespace std;

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
    uint16_t getOccurencesFromWord(string mot);
};

std::ostream& operator<<(std::ostream& os, const Lexique& lex);