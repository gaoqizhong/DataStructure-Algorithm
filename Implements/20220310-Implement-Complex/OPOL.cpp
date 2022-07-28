// operator overloading
#include <iostream>
#include "Complex.h"
using std::istream;
using std::ostream;

ostream &operator<<(ostream &os, const Complex &c)
{
    os << c.real << " + " << c.image << "i";
    return os;
}
istream &operator>>(istream &is, Complex &c)            
{
    // can't use const here
    is >> c.real >> c.image;
    return is;
}
Complex Complex::operator+(const Complex &c) const
{
    Complex result;
    result.real = real + c.real;
    result.image = image + c.image;
    return result;
}
Complex Complex::operator+(double n) const
{
    Complex result;
    result.real = real + n;
    result.image = image;
    return result;
}
Complex operator+(double n, const Complex &c)
{
    return c + n;
}
Complex Complex::operator-(const Complex &c) const
{
    return *this + (-c);
}
Complex Complex::operator-(double n) const
{
    return *this + (-n);
}
Complex operator-(double n, const Complex &c)
{
    return n + (-c);
}
Complex Complex::operator-() const
{
    Complex result;
    result.real = -real;
    result.image = -image;
    return result;
}
Complex Complex::operator*(const Complex &c) const
{
    Complex result;
    result.real = real * c.real - image * c.image;
    result.image = image * c.real + c.image * real;
    return result;
}
Complex Complex::operator*(double n) const
{
    Complex result;
    result.real = real * n;
    result.image = image * n;
    return result;
}
Complex operator*(double n, const Complex &c)
{
    return c * n;
}