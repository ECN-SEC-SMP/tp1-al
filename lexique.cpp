#include "lexique.hpp"

#include <string>
#include <iostream>
#include <string>

using namespace std;


// Getter
string Lexique::getNom() const { return this->nom; }
map<string, uint16_t> Lexique::getOccurences() { return this->occurences; }

// Setter
void Lexique::setNom(string nom) { this->nom = nom; }
void Lexique::setOccurences(map<string, uint16_t> occurences) { this->occurences = occurences; }


