#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main()
{
    double ar[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
    Queue Q1(ar, 5);

    Q1.display();

    while(true)
        cin.get();
    return 0;
}