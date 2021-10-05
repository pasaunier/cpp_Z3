#pragma once
#include "cartesien.hpp"
#include "point.hpp"
#include "polaire.hpp"

#include <vector>

class Nuage
{
  private:
    std::vector<Point*> vect;

  public:
    using const_iterator = std::vector<Point*>::const_iterator;
    using iterator = std::vector<Point*>::iterator;

    // void ajouter(Cartesien& car) { vect.push_back(&car); };
    // void ajouter(Polaire& pol) { vect.push_back(&pol); };
    
    void ajouter(Cartesien& car) { vect.push_back(new Cartesien(car)); };
    void ajouter(Polaire& pol) { vect.push_back(new Polaire(pol)); };

    // void ajouter(Point pt) { vect.push_back(pt); }; //ne marche pas

    int size() const { return vect.size(); };

    const_iterator begin() { return vect.begin(); }
    const_iterator end() { return vect.end(); }
};