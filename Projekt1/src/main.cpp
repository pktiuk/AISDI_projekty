#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string read(string filename)
{

    ifstream inFile;
    
    inFile.open(filename);

    string txt = ""; 
    
    char sign;

    while ( cin >> sign )
    {
        if( sign > 96 && sign < 123 )
            sign -= 32;
        if ( sign > 64 && sign < 91 )
            txt += sign;
    }

    return txt;
}

void write( string txt )
{
    cout << txt;
}

int main(int argc, char* argv) {
    
    // string txt = read();

    //write ( txt );

    

}