#pragma once

#include "carte.hpp"
#include "usine.hpp"

#include <memory>
#include <ostream>
#include <vector>

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t& paq, UsineCarte& usine)
{
    while(std::unique_ptr<Carte> val = usine.getCarte())
    {
        paq.push_back(std::move(val));
    }
}

std::ostream& operator<<(std::ostream& os, const paquet_t& paq)
{
    for(const auto& elem : paq)
    {
        os << elem->getValeur() << " ";
    }
    return os;
}