#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <iostream>
#include <cstdint>

using namespace std;

// Création de la classe
class Lexique {

protected:
    string nom;
    map<string, uint16_t> occurences;
public:
    // Constructeurs
    Lexique(string nom, string nom_fichier);
    Lexique(string nom);

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
    void subWordUsage(string mot, uint16_t occurences);
    uint16_t nombreDeMots();
    uint16_t getOccurencesFromWord(string mot);

    // Operateurs
    Lexique& operator+=(const Lexique& lex);
    Lexique& operator-=(const Lexique& lex);
};

std::ostream& operator<<(std::ostream& os, const Lexique& lex);