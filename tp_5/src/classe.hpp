#pragma once

class Classe
{
    double m_inf;
    double m_sup;
    unsigned m_quantite{0};

  public:
    Classe(double min, double max)
      : m_inf(min)
      , m_sup(max)
    {}

    void ajouter(unsigned val = 1) { m_quantite += val; }

    double getBorneInf() const { return m_inf; }
    double getBorneSup() const { return m_sup; }
    unsigned getQuantite() const { return m_quantite; }

    void setBorneSup(double a) { m_sup = a; }
    void setBorneInf(double a) { m_inf = a; }
    void setQuantite(unsigned a) { m_quantite = a; }

    bool operator<(const Classe& dos) const
    {
        if(m_inf < dos.m_inf)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Classe& dos) const
    {
        if(m_inf > dos.m_inf)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};