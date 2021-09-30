#pragma once
#include "point.hpp"
#include <iostream>

class Polaire;

class Cartesien: public Point
{

    private:
        double x;
        double y;

    public:
        Cartesien(){};
        Cartesien(const double, const double);
        virtual void afficher(std::ostream & flux) const ;
        double getX()const {return x;};
        double getY()const {return y;};

        void setX(double a_x) { x= a_x;};
        void setY(double a_y) { y= a_y;};
        friend std::ostream& operator<<(std::ostream&, const Cartesien&);
        void convertir(Polaire &) const;
        void convertir(Cartesien &) const;
};