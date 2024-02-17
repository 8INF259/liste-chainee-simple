#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>
#include "NoeudDouble.h"

template <typename Element> class ListeDouble {
  public :
    NoeudDouble<Element> *tete;                 // position du premier élément
    NoeudDouble<Element> *fin;                  // position du dernier élément

    ListeDouble();                                    // Constructeur
    ~ListeDouble();                                   // Destructeur
    void inserer(const Element &valeurCle);         // insère un élément à la position courante
    void insererFin(const Element &valeurCle);      // insère un élément à la fin de la liste
    void afficher() const;
    bool trouver(const Element &value);
    Element supprimer();                        // supprime le premier élément
    Element supprimerFin();
    bool listeVide();
};
#endif

// Constructeur
template <typename Element>
ListeDouble<Element>::ListeDouble(){          
   tete = fin = nullptr;            // crée le noeud entête
}

// Destructeur
template <typename Element>
ListeDouble<Element>::~ListeDouble() {
	NoeudDouble<Element> *courant = nullptr;

	while (tete != nullptr) {
		courant = tete;
		tete = tete->suivant;
		delete courant;
	}
}

// insère un élément à la tete
template <typename Element>
void ListeDouble<Element>::inserer(const Element &valeurCle) {
  NoeudDouble<int> *newNoeud = new NoeudDouble<Element>(valeurCle);

  newNoeud->suivant = tete;
  if (tete != nullptr) {
    tete->precedent = newNoeud;
  } else {
    fin = newNoeud;
  }
  tete = newNoeud;

}

// insère un élément à la fin de la liste
template <typename Element>
void ListeDouble<Element>::insererFin(const Element &valeurCle) {
  if (tete == nullptr) {
    inserer(valeurCle);
  } else {
    NoeudDouble<int> *newNoeud = new NoeudDouble<Element>(valeurCle);
    newNoeud->precedent = fin;
    fin->suivant = newNoeud;
    fin = newNoeud;
  }
}

template <typename Element>
void ListeDouble<Element>::afficher() const {
    NoeudDouble<Element>* noeudActuel = tete; 

    while (noeudActuel != nullptr) {
        std::cout << noeudActuel->cle << std::endl; 
        noeudActuel = noeudActuel->suivant;   
    }
}

template <typename Element>
bool ListeDouble<Element>::trouver(const Element &valeur) {
  NoeudDouble<int> *noeudActuel = tete;

  while (noeudActuel != nullptr && noeudActuel->cle != valeur) {
    noeudActuel = noeudActuel->suivant;
  }
  if (noeudActuel != nullptr) {
    return true;
  } else {
    return false;
  }
}

template <typename Element>
Element ListeDouble<Element>::supprimer() {
  if (tete != nullptr) {
    NoeudDouble<Element> *noeudASupprimer = tete;
    if (tete == fin) {
      fin = nullptr;
    }
    Element valeur = noeudASupprimer->cle;
    tete = tete->suivant;
    tete->precedent = nullptr;

    delete noeudASupprimer;
    return valeur;
  }
  return -1;
}

template <typename Element>
Element ListeDouble<Element>::supprimerFin() {
  if (tete != nullptr) {
    if (tete == fin) {
      return supprimer();
    } else {
      NoeudDouble<Element> *noeudASupprimer = fin;
      Element valeur = fin->cle;
      fin = fin->precedent;
      fin->suivant = nullptr;

      delete noeudASupprimer;

      return valeur;
    }
  } else {
    return -1;
  }
}

template <typename Element>
bool ListeDouble<Element>::listeVide(){
  return (tete != nullptr);
}
