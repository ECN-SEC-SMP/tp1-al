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
string Lexique::getNom() const { return this->nom; }
const map<string, uint16_t> &Lexique::getOccurences() const { return this->occurences; }

// Setter
void Lexique::setNom(string nom) { this->nom = nom; }
void Lexique::setOccurences(map<string, uint16_t> occurences) { this->occurences = occurences; }

// Fonctions
void Lexique::sauvegarderLexique(string texte) // Sauvegarde d'un lexique
{
    ofstream fichier(texte); //  Création du fichier
    if (fichier.is_open())   // Si ouverture OK
    {
        // On parcours la liste
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

void Lexique::supprimerMot(string nom) // Suppression d'un mot du lexique
{
    for (map<string, uint16_t>::iterator itmap = occurences.begin(); itmap != occurences.end(); ++itmap)
    {
        if (nom == itmap->first) // Si le mot de référence = mot présent dans le lexique, on le supprime
        {
            occurences.erase(itmap);
            cout << "Mot supprimé " << endl;
        }
    }
}

uint16_t Lexique::nombreDeMots() // Compter le nombre de mots différents dans un lexique
{
    return occurences.size(); // Retourne la taille de la map (nombre de mots)
}

uint16_t Lexique::getOccurencesFromWord(string mot)
{
    // Si le mot est déjà dans le lexique
    if (occurences.find(mot) != occurences.end())
    {
        return occurences[mot];
    }
    else
    {
        return 0;
    }
}

void Lexique::addWordUsage(string mot, uint16_t occ) {
    // Si le mot est déjà dans le lexique
    if (occurences.find(mot) != occurences.end())
    {
        occurences[mot] = occurences[mot] + occ;
    }
    else
    {
        occurences[mot] = occ;
    }
}

Lexique& Lexique::operator+=(const Lexique& lex) {
    for (map<string, uint16_t>::const_iterator itmap = lex.getOccurences().begin(); itmap != lex.getOccurences().end(); ++itmap)
    {
        addWordUsage(itmap->first, itmap->second);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Lexique& lex)
{
    for (map<string, uint16_t>::const_iterator itmap = lex.getOccurences().begin(); itmap != lex.getOccurences().end(); ++itmap)
    {
        os << itmap->first << " = " << itmap->second << endl;
    }
    return os;
}

std::ostream &operator-=(std::ostream &os, const Lexique &lex) // Opérateur -= surchargé
{
    for (map<string, uint16_t>::const_iterator itmap = lex.getOccurences().begin(); itmap != lex.getOccurences().end(); ++itmap)
    {
        map<string, uint16_t>::const_iterator found = lex.getOccurences().find(itmap->first);
        if (found != lex.getOccurences().end())
        {
            ;
        }
    }

    return os;
}
