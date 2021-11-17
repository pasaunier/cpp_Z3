#pragma once
#include "valeur.hpp"

#include <algorithm>
#include <exception>
#include <vector>

class Echantillon
{
  private:
    std::vector<Valeur> m_vect;

  public:
    size_t getTaille() const { return m_vect.size(); }

    std::vector<Valeur>& getVect() { return m_vect; }
    const std::vector<Valeur>& getVect() const { return m_vect; }

    // Valeur getMinimum() const
    // {
    //     return *std::min_element(
    //       m_vect.begin(), m_vect.end(), [](const Valeur& a, const Valeur& b) -> bool { return a > b; });
    // }

    Valeur getMinimum() const
    {
        if(m_vect.empty())
            throw std::domain_error("sdffds");

        return *std::min_element(m_vect.begin(), m_vect.end());
    }
    Valeur getMaximum() const
    {
        if(m_vect.empty())
            throw std::domain_error("sdffds");
        return *std::max_element(m_vect.begin(), m_vect.end());
    }

    void ajouter(Valeur arg) { m_vect.push_back(arg); }

    Valeur getValeur(unsigned arg)
    {
        // if(arg > m_vect.size())
        //     throw std::out_of_range("");

        return m_vect.at(arg); // at() a déja les erreurs :)
    }
};
