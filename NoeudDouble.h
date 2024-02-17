#ifndef NOEUDDOUBLE_H
#define NOEUDDOUBLE_H

template <typename Element> class NoeudDouble {
  public:
    Element cle;
    NoeudDouble *suivant;
    NoeudDouble *precedent;
    
    NoeudDouble() {
      suivant = nullptr;
      precedent = nullptr;
    }

    NoeudDouble(const Element &value) {
      cle = value;
      suivant = nullptr;
      precedent = nullptr;
    }
    
    ~NoeudDouble() {
    }
};
#endif