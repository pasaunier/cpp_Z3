#pragma once

class Valeur
{
  private:
    double m_nombre{0};

  public:
    Valeur() = default;
    Valeur(double arg)
      : m_nombre(arg)
    {}

    double getNombre() const { return m_nombre; }
    void setNombre(double arg) { m_nombre = arg; }

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