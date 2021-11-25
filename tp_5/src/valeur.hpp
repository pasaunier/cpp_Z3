#pragma once

class Valeur
{
  private:
    double m_nombre{0};
    std::string nom_{"inconnu"};

  public:
    Valeur() = default;
    Valeur(double arg, const std::string& nom)
      : m_nombre(arg)
      , nom_(nom)
    {}

    Valeur(double arg)
      : m_nombre(arg)
    {}

    double getNombre() const { return m_nombre; }
    double getNote() const { return m_nombre; }
    void setNombre(double arg) { m_nombre = arg; }
    std::string getEtudiant() const { return nom_; }
    void setNote(const double& arg) { m_nombre = arg; };
    void setEtudiant(const std::string& arg) { nom_ = arg; };

    bool operator<(const Valeur& arg) const
    {
        if(m_nombre < arg.getNombre())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Valeur& arg) const
    {
        if(m_nombre > arg.getNombre())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator==(const Valeur& arg) const
    {
        if(m_nombre == arg.getNombre())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};