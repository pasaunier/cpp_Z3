#include "point.hpp"

std::ostream& operator<<(std::ostream& flux, const Point& obj)
{
    obj.afficher(flux);
    return flux;
}

// void Point::convertir(Point& res) const
// {
//     // convertir(res);
// }