#include "polaire.hpp"

#include "cartesien.hpp"

#include <cmath>

Polaire::Polaire()
  : angle(0)
  , distance(0)
{}

Polaire::Polaire(const double a = 0.0, const double d = 0.0)
  : angle(a)
  , distance(d)
{}

void Polaire::afficher(std::ostream& flux) const
{
    flux << "("
         << "a=" << getAngle() << ";"
         << "d=" << getDistance() << ")";
}

std::ostream& operator<<(std::ostream& flux, const Polaire& obj)
{
    obj.afficher(flux);
    return flux;
}

void Polaire::convertir(Cartesien& res) const
{
    res.setX(distance * cos(angle * M_PI / 180));
    res.setY(distance * sin(angle * M_PI / 180));
}

void Polaire::convertir(Polaire& res) const
{
    res.setAngle(angle);
    res.setDistance(angle);
}

Polaire::Polaire(const Cartesien& obj)
  : angle(std::atan2(obj.getY(), obj.getX()) * 180 / M_PI)
  , distance(std::sqrt((obj.getX() * obj.getX()) + (obj.getY() * obj.getY())))
{}