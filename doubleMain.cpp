#include "ListeDouble.h"

int main() {
  ListeDouble<int> liste;
  liste.inserer(10);
  liste.insererFin(20);
  liste.inserer(30);
  liste.insererFin(40);
  liste.supprimer();
  liste.supprimerFin();
  liste.afficher();

  return 0;
}