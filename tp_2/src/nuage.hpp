#pragma once
#include "cartesien.hpp"
#include "polaire.hpp"

#include <vector>

template<typename T>
class Nuage
{
  private:
    std::vector<T> m_vect;

  public:
    size_t size() const { return m_vect.size(); };
    void ajouter(const T& elem) { m_vect.push_back(elem); };

    using const_iterator = typename std::vector<T>::const_iterator;
    using iterator = typename std::vector<T>::iterator;

    const_iterator begin() const { return m_vect.begin(); };
    const_iterator end() const { return m_vect.end(); };

    //   T retirer();
};

// un peu crado
template<typename T>
T barycentre_v1(const Nuage<T>& nuage)
{
    double retX{0};
    double retY{0};
    const double count = static_cast<double>(nuage.size());

    if(count <= 0)
    {
        return T(0, 0);
    }

    for(const auto& elem : nuage)
    {
        const Cartesien conv{elem};

        retX += conv.getX();
        retY += conv.getY();
    }

    Cartesien retval{retX / count, retY / count};

    return T(retval);
}

template<typename T>
T barycentre_v2(const Nuage<T>& nuage)
{
    double retX{0};
    double retY{0};
    const double count = static_cast<double>(nuage.size());

    if(count <= 0)
    {
        return T(0, 0);
    }

    for(const auto& elem : nuage)
    {
        const Cartesien conv{elem};

        retX += conv.getX();
        retY += conv.getY();
    }

    Cartesien retval{retX / count, retY / count};

    return T(retval);
}

// template<typename T, typename S>
// T barycentre_v2(const S<T>& nuage)
// {
//     double retX{0};
//     double retY{0};
//     const double count = static_cast<double>(nuage.size());

//     if(count <= 0)
//     {
//         return T(0, 0);
//     }

//     for(const auto& elem : nuage)
//     {
//         const Cartesien conv{elem};

//         retX += conv.getX();
//         retY += conv.getY();
//     }

//     Cartesien retval{retX / count, retY / count};

//     return T(retval);
// }

// POUR LE TEST 4b
// cette manière de faire n'est pas intelligente, une overload serait plus appropriée
// le calcul du barycentre avec la moyenne des angles et des hypot pour des vecteurs polaires
// est mathématiquement faux.

template<>
Polaire barycentre_v1<Polaire>(const Nuage<Polaire>& nuage)
{
    double ret_angle{0};
    double ret_dist{0};
    const double count = static_cast<double>(nuage.size());

    if(count <= 0)
    {
        return Polaire(0, 0);
    }

    for(const auto& elem : nuage)
    {
        ret_angle += elem.getAngle();
        ret_dist += elem.getDistance();
    }

    return Polaire(ret_angle / count, ret_dist / count);
}
