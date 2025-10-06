#include "lexique.hpp"

#include "utilitaire.hpp"

#include <cstdint>
#include <iostream>
#include <fstream>
#include <cstring>

Lexique::Lexique(string nom, string nom_fichier)
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
    mot = strtok(dup, " \r\n");

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
        cout << mot_string << " = " << occurences[mot_string] << endl;
        mot = strtok(NULL, " \r\n");
    }
    free(dup);
}

// Getter
string Lexique::getNom() const { return this->nom; }
map<string, uint16_t> Lexique::getOccurences() { return this->occurences; }

// Setter
void Lexique::setNom(string nom) { this->nom = nom; }
void Lexique::setOccurences(map<string, uint16_t> occurences) { this->occurences = occurences; }

// Fonctions
void Lexique::sauvegarderLexique(string texte) // Sauvegarde d'un lexique
{
    ofstream fichier(texte); //  Création du fichier
    if (fichier.is_open())   // Si ouverture OK
    {
        fichier << "Nom : " << this->nom << endl;
        for (map<string, uint16_t>::iterator itmap = occurences.begin(); itmap != occurences.end(); ++itmap)
        {
            fichier << "Occurence du mot '" << itmap->first << "' : " << itmap->second << endl;
        }
        fichier.close(); // Fermeture fichier
        cout << "Ecriture dans " << texte << " terminée." << endl;
    }
    else
    {
        cerr << "Erreur à l'ouverture" << endl;
    }
}

uint16_t Lexique::getOccurencesFromWord(string mot) {
    //Si le mot est déjà dans le lexique
    if(occurences.find(mot) != occurences.end()) {
        return occurences[mot];
    } else {
        return 0;
    }
}