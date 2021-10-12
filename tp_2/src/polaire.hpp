#pragma once
#include "point.hpp"

#include <iostream>

class Cartesien;

class Polaire : public Point
{
    double angle;
    double distance;

  public:
    Polaire();
    Polaire(const double, const double);
    Polaire(const Cartesien&);

    virtual void afficher(std::ostream&) const;

    double getAngle() const { return angle; };
    double getDistance() const { return distance; };

    void setAngle(const double ang) { angle = ang; };
    void setDistance(const double dist) { distance = dist; };

    friend std::ostream& operator<<(std::ostream& flux, const Polaire& obj);
    void convertir(Cartesien&) const override;
    void convertir(Polaire&) const override;
};