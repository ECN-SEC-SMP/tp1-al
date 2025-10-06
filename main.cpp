#include "lexique.hpp"
#include <cstdint>
#include <iostream>
#include <cstring>

int main()
{
    // std::cout << "Hello World" << std::endl;
    Lexique lex("Hello", "../notreDameDeParis_A.txt");

    uint16_t occ = lex.getOccurencesFromWord("new");
    std::cout << "Occurences du mot \"new\" (attendu=63): " << occ << std::endl;
    occ = lex.getOccurencesFromWord("coubeh");
    std::cout << "Occurences du mot \"coubeh\" (attendu=0): " << occ << std::endl;

    string texte = "test.txt";
    string mot = "Callot";
    int nbmot = 0;
    lex.supprimerMot(mot);
    lex.sauvegarderLexique(texte);
    nbmot = lex.nombreDeMots();
    cout << "Nombres de mots différents : " << nbmot << endl;

    //std::cout << lex;
    Lexique lex2("Lexique2", "../lesMiserables_A.txt");

    //lex+=lex2;
    lex -=lex2;
    lex2.sauvegarderLexique("lex2.txt");
    lex.sauvegarderLexique("after.txt");

    
}