#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
#include "OPOL.cpp"
using namespace std;

int main()
{
    Vector V1 = {};
    Vector V2 = {10.0, 37.0, Vector::POL};

    cout << "V1:" << endl;
    cout << V1;
    cout << "V2:" << endl;
    cout << V2;
    cout << "V1.reset(3.0, 4.0):" << endl;
    V1.reset(3.0, 4.0);
    cout << V1;
    cout << "- V1:" << endl;
    cout << -V1;
    cout << "V1 * 2:" << endl;
    cout << V1 * 2;
    cout << "V1 + V2:" << endl;
    cout << V1 + V2;
    cout << "V1 - V2:" << endl;
    cout << V1 - V2;
    cout << "V1 * V2:" << endl;
    cout << V1 * V2;

    while(true)
        cin.get();
    return 0;
}