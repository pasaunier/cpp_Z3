#pragma once
#include "carte.hpp"

#include <memory>

class UsineCarte
{
  private:
    static unsigned s_cur_val;

  public:
    std::unique_ptr<Carte> getCarte()
    {
        if(s_cur_val < 52)
        {
            std::unique_ptr<Carte> ptr(new Carte(s_cur_val));
            ++s_cur_val;
            return ptr;
        }
        else
        {
            return nullptr;
        }
    };
};
