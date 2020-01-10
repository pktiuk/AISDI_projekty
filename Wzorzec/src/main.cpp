#include <iostream>
#include <testing.h>

int main()
{
    cout << "Przypadki brzegowe:\n";
    cout<<"naiwny: ";
    if(testN())
        cout<<"OK\n";
    else
        cout<<"ERROR\n";
    
    cout << "BM: ";
    if(testBM())
        cout<<"OK\n";
    else
        cout<<"ERROR\n";

    cout << "automatyczny BM: ";
    for( int i = 0; i < 20; ++i )
        if(autoTestBM(i))
            cout << "OK\n";
        else
            cout << "ERROR\n";
    
}