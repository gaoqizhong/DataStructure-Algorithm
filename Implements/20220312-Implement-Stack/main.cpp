#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main()
{
    double ar[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
    Stack S1(ar, 5);

    S1.display();

    while(true)
        cin.get();
    return 0;
}