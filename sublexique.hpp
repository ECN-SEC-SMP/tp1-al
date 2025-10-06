#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <iostream>
#include <cstdint>

using namespace std;

// Création de la classe
class SubLexique
{

private:
    string nom;
    map<string, uint16_t> occurences;
    uint16_t ligne;

public:
    // Constructeurs
    SubLexique(string nom, string nom_fichier);

    // Accesseurs
    string getNom() const;
    const map<string, uint16_t> &getOccurences() const;

    // Mutateurs
    void setNom(string nom);
    void setOccurences(map<string, uint16_t> occurences);
};