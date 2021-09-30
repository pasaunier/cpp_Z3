#include "cartesien.hpp"

#include "cmath"
#include "polaire.hpp"

Cartesien::Cartesien(const double x = 0.0, const double y = 0.0)
  : x(x)
  , y(y)
{}

void Cartesien::afficher(std::ostream& flux) const
{
    flux << "("
         << "x=" << getX() << ";"
         << "y=" << getY() << ")";
}

std::ostream& operator<<(std::ostream& flux, const Cartesien& obj)
{
    obj.afficher(flux);
    return flux;
}

void Cartesien::convertir(Polaire& res) const
{
    res.setAngle(std::atan2(y, x) * 180 / M_PI);
    res.setDistance(std::sqrt((x * x) + (y * y)));
}

void Cartesien::convertir(Cartesien& res) const
{
    res.setX(x);
    res.setY(y);
}

Cartesien::Cartesien(const Polaire& obj)
  : x(obj.getDistance() * cos(obj.getAngle() * M_PI / 180))
  , y(obj.getDistance() * sin(obj.getAngle() * M_PI / 180))
{}