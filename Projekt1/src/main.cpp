#include <iostream>
#include <fstream>
#include <string>
#include <conversion.hpp>

using namespace std;

string read(string filename)
{

    ifstream inFile;
    
    inFile.open(filename);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string txt = ""; 
    
    char sign;

    while ( inFile >> sign )
    {
        if( sign > 96 && sign < 123 )
            sign -= 32;
        if ( ( sign > 64 && sign < 91 ) || sign == 32 )
            txt += sign;
    }

    return txt;
}

void write( string txt )
{
    cout << txt;
}

int main(int argc, char *argv[]) {

    string file;

    if (argc > 1) {
        file  = argv[1];
    }

    string txt = read(file);

    printMorse(txt);

    

}