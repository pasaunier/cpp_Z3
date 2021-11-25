#pragma once
#include "classe.hpp"
#include "echantillon.hpp"
#include "valeur.hpp"

#include <functional>
#include <iostream>
#include <map>
#include <set>

template<typename T = std::less<Classe>>
class Histogramme
{
    std::set<Classe, T> m_classes;
    // std::multimap<Classe, Valeur>;

  public:
    const Classe& getValeurs(){return Classe();};

    Histogramme(double min, double max, unsigned qte)
    {
        double amp = (max - min) / qte;
        for(unsigned i = 0; i < qte; ++i)
        {
            m_classes.insert(Classe(min + amp * i, min + amp * i + amp));
        }
    }

    // template<typename COMPARATEUR>
    template<typename COMPARATEUR2>
    Histogramme(const Histogramme<COMPARATEUR2>& histo)
    //   : m_borneInf(histo.getBorneInf())
    //   , m_borneSup(histo.getBorneSup())
    {
        // Insertion directe
        m_classes.insert(histo.getClasses().begin(), histo.getClasses().end());
        // valeurs_.insert(histo.getValeurs().begin(), histo.getValeurs().end());
    }

    std::set<Classe, T>& getClasses() { return m_classes; }
    const std::set<Classe, T>& getClasses() const { return m_classes; }

    void ajouter(const Valeur& valeur)
    {
        // Recherche avec iterateurs
        auto it = m_classes.begin(); // auto = classes_t::const_iterator

        while(it != m_classes.end())
        {
            if(valeur.getNombre() >= it->getBorneInf() && valeur.getNombre() < it->getBorneSup())
                break;
            ++it;
        }

        if(it != m_classes.end())
        {
            Classe c = *it;
            c.ajouter();
            m_classes.erase(it);
            m_classes.insert(c);

            // valeurs_.insert(std::make_pair(c, valeur));
        }
    }

    void ajouter(const Echantillon& ech)
    {
        for(unsigned i = 0; i < ech.getTaille(); ++i)
            ajouter(ech.getValeur(i));
    }
};

template<typename T>
class ComparateurQuantite
{
  public:
    bool operator()(const T& a, const T& b) const
    {
        return (a.getQuantite() == b.getQuantite() ? a < b : a.getQuantite() > b.getQuantite());
    }
};