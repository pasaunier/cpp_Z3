#pragma once
#include "carte.hpp"

#include <memory>

class UsineCarte
{
  private:
    unsigned m_cur_val{0};
    const unsigned m_max_val;

  public:
    UsineCarte(unsigned val = 52)
      : m_max_val(val){};

    UsineCarte(UsineCarte&) = delete;
    UsineCarte& operator()(UsineCarte&) = delete;
    UsineCarte& operator=(UsineCarte&) = delete;

    std::unique_ptr<Carte> getCarte()
    {
        if(m_cur_val < m_max_val)
        {
            std::unique_ptr<Carte> ptr(new Carte(m_cur_val));
            ++m_cur_val;
            return ptr;
        }
        else
        {
            return nullptr;
        }
    };
};
