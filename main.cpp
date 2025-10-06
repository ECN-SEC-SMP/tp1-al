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
    occ = lex.getOccurencesFromWord("feur");
    std::cout << "Occurences du mot \"feur\" (attendu=0): " << occ << std::endl;

    string texte = "test.txt";
    lex.sauvegarderLexique(texte);

    //std::cout << lex;
}