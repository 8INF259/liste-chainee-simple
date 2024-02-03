#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H
#include "Noeud.h"

template <typename Element> class Liste {
  public :
    Noeud<Element> *tete;                       // position du premier élément
    Noeud<Element> *fin;                        // position du dernier élément
    Noeud<Element> *courant;                    // position de l'élément courant

    Liste();                                    // Constructeur
    ~Liste();                                   // Destructeur
    void inserer(const Element &valeurCle);         // insère un élément à la position courante
    void insererFin(const Element &valeurCle);      // insère un élément à la fin de la liste
    void afficher() const;
};
#endif

// Constructeur
template <typename Element>
Liste<Element>::Liste(){          
   tete = fin = nullptr;            // crée le noeud entête
}

// Destructeur
template <typename Element>
Liste<Element>::~Liste() {
	Noeud<Element> *courant = nullptr;

	while (tete != nullptr) {
		courant = tete;
		tete = tete->suivant;
		delete courant;
	}
}

// insère un élément à la position courante
template <typename Element>
void Liste<Element>::inserer(const Element &valeurCle) {
  Noeud<int> *newNoeud = new Noeud<Element>(valeurCle);
  newNoeud->suivant = tete;
  if (tete == nullptr) {
    fin = newNoeud;
  }
  tete = newNoeud;
  courant = tete;
}

// insère un élément à la fin de la liste
template <typename Element>
void Liste<Element>::insererFin(const Element &valeurCle) {
  if (tete == nullptr) {
    inserer(valeurCle);
  } else {
    Noeud<int> *newNoeud = new Noeud<Element>(valeurCle);
    fin->suivant = newNoeud;
    fin = newNoeud;
  }
}

template <typename Element>
void Liste<Element>::afficher() const {
    Noeud<Element>* noeudActuel = tete; 

    while (noeudActuel != nullptr) {
        std::cout << noeudActuel->cle << std::endl; 
        noeudActuel = noeudActuel->suivant;   
    }
}