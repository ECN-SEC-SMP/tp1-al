#ifndef __lexique_h
#define __lexique_h
#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <iostream>
#include <cstdint>
#include <fstream>

using namespace std;

// Création de la classe
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

    // Fonctions
    void sauvegarderLexique(string texte);
    void supprimerMot(string nom);
    uint16_t nombreDeMots();
    uint16_t getOccurencesFromWord(string mot);
};

#endif