#pragma once
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

#include <vector>

class Nuage
{
  private:
    std::vector<Point*> vect;

  public:
    void ajouter(Cartesien car) { vect.push_back(&car); };
    void ajouter(Polaire pol) { vect.push_back(&pol); };
    size_t size() const { return vect.size(); };
};