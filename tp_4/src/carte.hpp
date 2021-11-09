#pragma once

#include <iostream>
#include <memory>
class UsineCarte;

class Carte
{
  private:
    unsigned m_valeur;
    static unsigned s_compteur;

    Carte(unsigned arg)
      : m_valeur(arg)
    {
        ++s_compteur;
    }

        friend class UsineCarte;

  public:
    unsigned getValeur() const { return m_valeur; };
    static unsigned getCompteur() { return s_compteur; };

    Carte(Carte&) = delete;
    Carte& operator()(Carte&) = delete;
    Carte& operator=(Carte&) = delete;
    ~Carte() { --s_compteur; }
};