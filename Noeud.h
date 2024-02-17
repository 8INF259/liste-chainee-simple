#ifndef NOEUD_H
#define NOEUD_H

template <typename Element> class Noeud {
  public:
    Element cle;
    Noeud<Element> *suivant;
    
    Noeud() {
      suivant = nullptr;
    }

    Noeud(const Element &value) {
      cle = value;
      suivant = nullptr;
    }
    
    ~Noeud() {
    }
};
#endif