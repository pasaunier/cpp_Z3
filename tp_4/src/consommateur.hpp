#pragma once
#include "ressource.hpp"

class Consommateur
{
  private:
    unsigned m_nombre{0};
    std::shared_ptr<Ressource> m_res{nullptr};

  public:
    // ici on peut copier le shared_ptr
    Consommateur(unsigned nbr, std::shared_ptr<Ressource>& ptr)
      : m_nombre(nbr)
      , m_res(ptr)
    {}
    void puiser() {
        m_res->consommer(m_nombre);

        if(m_res->getStock() == 0)
        {
        m_res = nullptr;
        }
    }
};