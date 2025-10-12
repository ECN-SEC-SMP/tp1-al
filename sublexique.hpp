#pragma once

// Bibliothèques
#include <string>
#include <map>
#include <cstdint>
#include "lexique.hpp"

using namespace std;

// Création de la classe
class SubLexique : public Lexique
{

private:
    multimap<string, uint32_t> lignes;

public:
    // Constructeurs
    SubLexique(string nom, string nom_fichier);

    void sauvegarderLexique(string texte);
};