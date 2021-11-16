#pragma once
#include "classe.hpp"
#include "echantillon.hpp"
#include "valeur.hpp"

class Histogramme
{
    std::vector<Classe> m_classes;

  public:
    Histogramme(double min, double max, unsigned qte)
    {
        double amp = (max - min) / qte;
        for(unsigned i = 0; i < qte; ++i)
        {
            m_classes.push_back(Classe(min + amp * i, min + amp * i + amp));
        }
    }
    std::vector<Classe>& getClasses() { return m_classes; }

    void ajouter(double val)
    {
        for(auto& elem : m_classes)
        {
            if(elem.addif(val))
                break;
        }
    }

    void ajouter(Echantillon val)
    {
        for(auto& elem : m_classes)
        {
            if(val.getMinimum().getNombre() >= elem.getBorneInf() && val.getMaximum().getNombre() <= elem.getBorneSup())
            {
                elem.ajouter(val.getTaille());
                        }
        }
    }
};