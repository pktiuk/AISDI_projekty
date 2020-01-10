#include <iostream>
#include <testing.h>

int main()
{
    cout<<"naiwny: ";
    if(testN())
        cout<<"OK\n";
    else
        cout<<"ERROR\n";

    cout << "BM: ";
    if(testBM(2))
        cout << "OK\n";
    else
        cout << "ERROR\n";
    
}