#pragma once
#include "cartesien.hpp"
#include "point.hpp"
#include "polaire.hpp"

#include <vector>

class Nuage
{
  private:
    std::vector<Point*> vect; // devrait être std::unique_ptr

  public:
    using const_iterator = std::vector<Point*>::const_iterator;
    using iterator = std::vector<Point*>::iterator;

    // attention ne pas faire ça :
    // void ajouter(Cartesien& car) { vect.push_back(&car); };
    // void ajouter(Polaire& pol) { vect.push_back(&pol); };
    // les tests passent avec mais ce sont des copies de variables locales.
    // En cas de changement de scope, segfault+++

    void ajouter(Cartesien& car) { vect.push_back(new Cartesien(car)); };
    void ajouter(Polaire& pol) { vect.push_back(new Polaire(pol)); };
    // ajouter(Point pt) est une mauvaise idée. il faudrait trouver le type de pt à
    // l'exe, ce qui pose pas mal de pb
    // void ajouter(Point pt) { vect.push_back(pt); };

    int size() const { return vect.size(); };

    const_iterator begin() { return vect.begin(); }
    const_iterator end() { return vect.end(); }

    Cartesien barycentre(Nuage n) const;
};