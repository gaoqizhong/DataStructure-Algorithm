// operator overloading
#include <iostream>
#include "Vector.h"
using std::ostream;

Vector Vector::operator+(const Vector &b) const
{
    return Vector(x + b.x, y + b.y);
}
Vector Vector::operator-(const Vector &b) const
{
    return Vector(x - b.x, y - b.y);
}
Vector Vector::operator-() const
{
    return Vector(-x, -y);
}
Vector Vector::operator*(double n) const
{
    return Vector(n * x, n * y);
}
Vector Vector::operator*(const Vector &b) const
{
    return Vector(x * b.x, y * b.y);
}
Vector operator*(double n, const Vector &b)
{
    return b * n;               // call the method in the class
}
ostream &operator<<(ostream &os, const Vector &v)
{
    os << "(x, y) = (" << v.x << ", " << v.y << ")\n"
       << "mag = " << v.mag << "   ang = " << v.ang << "\n";
    return os;
}