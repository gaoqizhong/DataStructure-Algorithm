#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using std::istream;
using std::ostream;

class Complex
{
    private:
        double real;
        double image;
    public:
        Complex();
        Complex(double x, double y);    
        // OPOL: operator overloading
        // operator +
        Complex operator+(const Complex &c) const;                      // complex + complex
        Complex operator+(double n) const;                              // complex + real
        friend Complex operator+(double n, const Complex &c);           // real + complex
        // operator -
        Complex operator-(const Complex &c) const;                      // complex - complex
        Complex operator-(double n) const;                              // complex - real
        friend Complex operator-(double n, const Complex &c);           // real + complex
        Complex operator-() const;                                      // -complex
        // operator *
        Complex operator*(const Complex &c) const;                      // complex * complex
        Complex operator*(double n) const;                              // complex * real
        friend Complex operator*(double n, const Complex &c);           // real * complex
        // operator >>
        friend istream &operator>>(istream &is, Complex &c);            // cin >> complex
        // operator <<
        friend ostream &operator<<(ostream &os, const Complex &c);      // cout << complex
};

#endif