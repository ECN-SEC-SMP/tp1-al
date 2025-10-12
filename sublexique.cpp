#include "sublexique.hpp"

#include "lexique.hpp"
#include "utilitaire.hpp"

#include <cstdint>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

SubLexique::SubLexique(string nom, string nom_fichier) : Lexique(nom)
{
    //Relire le fichier à la recherche des mots enregistrés par le constructeur de la classe Lexique
    string contenu;
    if (!util::readFileIntoString(nom_fichier, contenu))
    {
        cerr << "Impossible de lire le fichier." << endl;
    }

    util::remove_punctuation(contenu);

    istringstream stream(contenu);
    string line;
    uint32_t line_number = 1;
    //Pour chaque ligne
    while (std::getline(stream, line)) {
        char *dup = strdup(line.c_str());
        char *mot;
        mot = strtok(dup, "“”‘’- \r\n");

        //Pour chaque mot de la ligne
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

            //Ajout à la multimap
            lignes.insert({mot_string, line_number});

            //Prochain mot
            mot = strtok(NULL, "“”‘’- \r\n");
        }

        free(dup);

        line_number++;
    }

}

void SubLexique::sauvegarderLexique(string texte) {
    ofstream fichier(texte); // Création du fichier
    string old_key;
    if (fichier.is_open())   // Si ouverture OK
    {
        // On parcours la liste
        for (const auto& itmap : lignes)
        {
            //Nouveau mot
            if(old_key != itmap.first) {
                old_key = itmap.first;
                fichier << endl; //Retour à la ligne
                fichier << "Occurences du mot " << itmap.first << ": " << itmap.second << ", ";
            } else { //On continue la ligne actuelle
                fichier << itmap.second << ", ";
            }
        }
        fichier.close(); // Fermeture fichier
        cout << "Ecriture dans " << texte << " terminée." << endl;
    }
    else
    {
        cerr << "Erreur à l'ouverture" << endl;
    }
}