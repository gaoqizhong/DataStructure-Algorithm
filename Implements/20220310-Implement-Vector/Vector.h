#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
using std::ostream;

class Vector
{
    public:
        enum Mode{RECT, POL};                                       // RECT for rectangular, POL for polar modes
    private:
        double x;
        double y;
        double mag;                                                 // length
        double ang;                                                 // direction in radian
        Mode mode;                                                  // RECT or POL
        void set_x_y();
        void set_mag_ang();
    public:
        Vector();                                                   // RECT mode is used by default
        Vector(double n1, double n2, Mode form = RECT);             // RECT mode is used by default
        void reset(double n1, double n2, Mode form = RECT);         // RECT mode is used by default
        void setmode(Mode form = RECT);                             // RECT mode is used by default
        // OPOL: operator overloading
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        Vector operator*(const Vector &b) const;
        friend Vector operator*(double n, const Vector &b);
        friend ostream &operator<<(ostream &os, const Vector &v);
};

#endif