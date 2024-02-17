#include <iostream>
#include "Liste.h" // Supondo que este arquivo contém as definições das classes Liste e Noeud

int main() {
    ListeDouble<int> maListe;
    maListe.afficher();
    std::cout << "======"  << std::endl;
    
    maListe.insererFin(10);
    std::cout << "Tete: " << maListe.tete->cle << std::endl;
    std::cout << "Fin: " << maListe.fin->cle << std::endl;
    maListe.afficher();
    std::cout << "======"  << std::endl;
    
    maListe.inserer(20);
    std::cout << "Tete: " << maListe.tete->cle << std::endl;
    std::cout << "Fin: " << maListe.fin->cle << std::endl;
    maListe.afficher();
    std::cout << "======"  << std::endl;

    maListe.inserer(30);
    std::cout << "Tete: " << maListe.tete->cle << std::endl;
    std::cout << "Fin: " << maListe.fin->cle << std::endl;
    maListe.afficher();
    std::cout << "======"  << std::endl;

    maListe.insererFin(40);
    std::cout << "Tete: " << maListe.tete->cle << std::endl;
    std::cout << "Fin: " << maListe.fin->cle << std::endl;
    maListe.afficher();
    std::cout << "======"  << std::endl;

    maListe.insererFin(15);
    std::cout << "Tete: " << maListe.tete->cle << std::endl;
    std::cout << "Fin: " << maListe.fin->cle << std::endl;
    maListe.afficher();

    return 0;
}
