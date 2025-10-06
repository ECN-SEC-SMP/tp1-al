#ifndef __lexique_h
#define __lexique_h
pragma once

// Bibliothèques
#include <string>
#include <iostream>
using namespace std;

private:
    string nom;

public:
    int occurence;

    // Constructeurs
    Lexique(string nom, string occurence);
    Lexique(string nom);

    // Accesseurs

    // Mutateurs

};

#endif