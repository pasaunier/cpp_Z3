#pragma once
#include "valeur.hpp"

#include <algorithm>
#include <vector>

class Echantillon
{
  private:
    std::vector<Valeur> m_vect;

  public:
    size_t getTaille() const { return m_vect.size(); }

    // Valeur getMinimum() const
    // {
    //     return *std::min_element(
    //       m_vect.begin(), m_vect.end(), [](const Valeur& a, const Valeur& b) -> bool { return a > b; });
    // }
    Valeur getMinimum() const { return *std::min_element(m_vect.begin(), m_vect.end()); }

    void ajouter(Valeur arg) { m_vect.push_back(arg); }
};