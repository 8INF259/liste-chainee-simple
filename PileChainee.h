#ifndef PILECHAINEE_H
#define PILECHAINEE_H

#include "Liste.h"

template <typename Element>
class Pile {
  public:
    Liste<Element> *elements;  // liste d'elements
    int taille;         // nombre d’élément dans la pile

    Pile();
    ~Pile();
    int laTaille() const;
    bool pileVide() const;
    Element sommet() const;
    void empiler(const Element& element); 
    void depiler();  
};

template <typename Element>
Pile<Element>::Pile() {
  elements = new Liste<Element>();
  taille = 0;
}

template <typename Element>
Pile<Element>::~Pile() {
  delete elements;
}


template <typename Element>
int Pile<Element>::laTaille() const {
  return taille;
}

template <typename Element>
bool Pile<Element>::pileVide() const {
  return taille == 0;
}

template <typename Element>
Element Pile<Element>::sommet() const {
  if (!pileVide()) {
    return elements->laTete();
  } else {
    return 0;
  }
}

template <typename Element>
void Pile<Element>::empiler(const Element& element) {
  taille++;
  elements->inserer(element);
} 

template <typename Element>
void Pile<Element>::depiler() {
  taille--;
  elements->supprimer();
} 

#endif