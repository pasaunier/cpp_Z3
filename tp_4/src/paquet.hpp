#pragma once

#include "carte.hpp"
#include "usine.hpp"

#include <memory>
#include <vector>

using paquet_t = std::vector<std::unique_ptr<Carte>>;

void remplir(paquet_t paq, UsineCarte usine)
{
    while(usine.getCarte() != nullptr)
    {
        // paquet_t.push_back(usine.getCarte());
    }
}