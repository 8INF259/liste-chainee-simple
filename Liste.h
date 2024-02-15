#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H
#include "Noeud.h"

template <typename Element> class Liste {
  public :
    Noeud<Element> *tete;                       // position du premier élément
    Noeud<Element> *fin;                        // position du dernier élément
    // Noeud<Element> *courant;                    // position de l'élément courant

    Liste();                                    // Constructeur
    ~Liste();                                   // Destructeur
    void inserer(const Element &valeurCle);         // insère un élément à la position courante
    void insererFin(const Element &valeurCle);      // insère un élément à la fin de la liste
    void afficher() const;
    bool trouver(const Element &value);
    Element supprimer();                        // supprime le premier élément
    Element supprimerFin();
    void supprimerParCle(Element cleRecherchee);
    bool listeVide();
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

// insère un élément à la tete
template <typename Element>
void Liste<Element>::inserer(const Element &valeurCle) {
  Noeud<int> *newNoeud = new Noeud<Element>(valeurCle);
  newNoeud->suivant = tete;
  if (tete == nullptr) {
    fin = newNoeud;
  }
  tete = newNoeud;
  // courant = tete;
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

template <typename Element>
bool Liste<Element>::trouver(const Element &valeur) {
  Noeud<int> *noeudActuel = tete;

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
Element Liste<Element>::supprimer() {
  if (tete != nullptr) {
    Noeud<Element> *noeudASupprimer = tete;
    if (tete == fin) {
      fin = nullptr;
    }
    Element valeur = noeudASupprimer->cle;
    tete = tete->suivant;
    delete noeudASupprimer;
    return valeur;
  }
  return -1;
}

template <typename Element>
Element Liste<Element>::supprimerFin() {
  if (tete != nullptr) {
    if (tete == fin) {
      return supprimer();
    } else {
      Noeud<Element> *noeudActuel = tete;
      while (noeudActuel->suivant != fin) {
        noeudActuel = noeudActuel->suivant;
      }
      Element valeur = fin->cle;
      delete fin;
      noeudActuel->suivant = nullptr;
      fin = noeudActuel;
      return valeur;
    }
  } else {
    return -1;
  }
}

template <typename Element>
bool Liste<Element>::listeVide(){
  return (tete != nullptr);
}

template <typename Element>
void Liste<Element>::supprimerParCle(Element cleRecherchee){
  if(!listeVide()) {
    if (tete->cle == cleRecherche) {
      supprimer();
    }
    else {
      Noeud* noeudActuel = tete;

      while(noeudActuel->suivant != nullptr 
            && noeudActuel->suivant->cle != cleRecherchee) {
              noeudActuel = noeudActuel->suivant;
      }

      if (noeudActuel->suivant != nullptr) {
        Noeud* noeudASuprrimer = noeudActuel->suivant;
        noeudActuel->suivant = noeudASupprimer->suivant;

        if (noeudASupprimer == fin) {
          fin = noeudActuel;
        }

        delete noeudASupprimer;
      }
    }
  }
}