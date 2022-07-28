#include <iostream>
#include "Complex.h"

Complex::Complex()
{
    real = image = 0.0;
}
Complex::Complex(double x, double y)
{
    real = x;
    image = y;
}
