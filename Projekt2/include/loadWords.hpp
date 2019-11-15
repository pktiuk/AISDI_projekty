#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

std::vector<string> read(string filename,int num=INT32_MAX)
{
    int i=0;
    vector<string> wczytano;
    ifstream inFile;
    
    inFile.open(filename);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    
    string word;

    while ( inFile >> word || i < num)
    {
        wczytano.push_back(word);
        i++;
    }

    return wczytano;
}