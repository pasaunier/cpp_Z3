#pragma once
#include <memory>
#include <ostream>
#include <vector>

class Ressource
{
  private:
    unsigned m_stock{0};

  public:
    Ressource(unsigned val)
      : m_stock(val){};

    unsigned getStock() const { return m_stock; };

    void consommer(unsigned nbr)
    {
        if(m_stock >= nbr)
        {
            m_stock -= nbr;
        }
        else
        {
            m_stock = 0;
        }
    };
};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream& operator<<(std::ostream& os, ressources_t& res)
{
    for(const auto& elem : res)
    {
        if(elem.expired())
        {
            os << "- ";
        }
        else
        {
            os << *elem.getStock() << ' ';
        }
    }
    os << std::endl;
    return os;
}
