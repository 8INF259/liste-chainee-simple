#ifndef PILETABLEAU_H
#define PILETABLEAU_H

const int TAILLE_DE_PILE = 10;

template <typename Element>
class Pile {
  public :
    int taille;                            // Taille Maximum de la pile
    int sommet;                            // indice de la position d'element au sommet
    Element* elements;                     // Tableau contenant les éléments de la pile

    Pile(const int max = TAILLE_DE_PILE) ; // Constructeur
    ~Pile() ;                              // destructeur
    void empiler(const Element& element);  // ajoute un élément au dessus de la pile
    Element depiler();                     // retire un élément du sommet de la pile
    void viderPile();                      // enlève tous les éléments de la pile
    Element sommet() const;                // Renvoie la valeur du sommet de la pile
    bool pileVide() const;                 // Renvoie vrai (true) si la pile est vide
};

template <typename Element>
Pile<Element>::Pile(const int max) {
  taille = max;
  sommet = -1;
  elements = new Element[taille];
}

template <typename Element>
Pile<Element>::~Pile () {
  delete elements;
}

template <typename Element>
void Pile<Element>::viderPile() {
  sommet = -1;
}

template <typename Element>
void Pile<Element>::empiler(const Element& nouveauElement) {
  if (sommet < taille) {
    elements[++sommet] = nouveauElement;
  }
}

template <typename Element>
Element Pile<Element>::depiler() {
  if (!pileVide()) {
    return elements[sommet--];
  }
}

template <typename Element>
Element Pile<Element>::sommet() const {
  if (!pileVide()) {
    return elements[sommet];
  }
}

template <typename Element>
bool Pile<Element>::pileVide() const {
  return sommet == -1;
}

#endif