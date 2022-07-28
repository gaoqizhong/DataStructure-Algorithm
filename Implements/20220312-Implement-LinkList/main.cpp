#include <iostream>
#include "LinkList.h"
#include "LinkList.cpp"
using namespace std;

int main()
{
    double ar[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
    LinkList L1(ar, 5);
    
    L1.display();

    while(true)
        cin.get();
    return 0;
}