#pragma once

#include <memory>
class UsineCarte;

class Carte
{
  private:
    unsigned m_valeur;

    Carte(unsigned arg)
      : m_valeur(arg)
    {}

    friend class UsineCarte;

  public:
    unsigned getValeur() const { return m_valeur; };

    Carte(Carte&) = delete;
    Carte& operator()(Carte&) = delete;
    Carte& operator=(Carte&) = delete;

};