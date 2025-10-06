#ifndef __lexique_h
#define __lexique_h
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
    int occurence;

    // Constructeurs
    Lexique(string nom, string nom_fichier);

    // Accesseurs
    string getNom() const;
    map<string, uint16_t> getOccurences();

    // Mutateurs
    void setNom(string nom);
    void setOccurences(map<string, uint16_t> occurences);

};


#endif