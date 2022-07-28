#include <iostream>
#include <cmath>
#include "Vector.h"

const double Rad_to_deg = 45.0 / atan(1.0);
void Vector::set_x_y()
{
    x = mag * cos(ang);
    y = mag * sin(ang);
}
void Vector::set_mag_ang()
{
    mag = sqrt(x * x + y * y);
    if (x == 0.0 && y == 0.0)
        ang = 0.0;
    else
        ang = atan2(y, x);
}
Vector::Vector()
{
    x = y = mag = ang = 0.0;
    mode = RECT;
}
Vector::Vector(double n1, double n2, Mode form)
{
    if(form == POL)
    {
        mode = POL;
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x_y();
    }
    else
    {
        mode = RECT;
        x = n1;
        y = n2;
        set_mag_ang();
    }
}
void Vector::reset(double n1, double n2, Mode form)
{
    if(form == POL)
    {
        mode = POL;
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x_y();
    }
    else
    {
        mode = RECT;
        x = n1;
        y = n2;
        set_mag_ang();
    }  
}
void Vector::setmode(Mode form)
{
    if(form == POL)
        mode = POL;
    else
        mode = RECT;
}