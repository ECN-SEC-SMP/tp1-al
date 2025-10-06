#include "sublexique.hpp"

#include "utilitaire.hpp"

#include <cstdint>
#include <iostream>
#include <fstream>
#include <cstring>

SubLexique::SubLexique(string nom, string nom_fichier)
{
    string contenu;
    if (!util::readFileIntoString(nom_fichier, contenu))
    {
        cerr << "Impossible de lire le fichier." << endl;
    }

    util::remove_punctuation(contenu);

    // Découpage par mots
    // Il faut dupliquer la string pour respecter le const de ".c_str()"
    char *dup = strdup(contenu.c_str());
    char *mot;
    mot = strtok(dup, "“”‘’- \r\n");

    while (mot != NULL)
    {
        string mot_string = string(mot);
        // Si le mot est déjà dans le lexique
        if (occurences.find(mot_string) != occurences.end())
        {
            occurences[mot_string] = occurences[mot_string] + 1;
        }
        else
        {
            occurences[mot_string] = 1;
        }
        mot = strtok(NULL, "“”‘’- \r\n");
    }
    free(dup);
}

// Getter
string SubLexique::getNom() const { return this->nom; }
const map<string, uint16_t> &SubLexique::getOccurences() const { return this->occurences; }

// Setter
void SubLexique::setNom(string nom) { this->nom = nom; }
void SubLexique::setOccurences(map<string, uint16_t> occurences) { this->occurences = occurences; }
