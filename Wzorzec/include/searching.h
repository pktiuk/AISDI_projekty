#ifndef SEARCH

#define SEARCH

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 1000000;


std::vector<int>findN(std::string const & str, std::string const & text)
{
    vector<int> v;
    int size = text.size() - str.size();
    for( int i = 0; i <= size; ++i )
    {
        bool equal = true;
        for( int j = 0; j < str.size(); ++j )
        {
            if( text[i+j] != str[j] )
            {
                equal = false;
                break;
            }
        }
        if( equal && str != "" )
            v.push_back(i);
    }

    return v;
}


int indeks(char c)
{
    return c - 'a';
}


int shiftBM[MAX_SIZE];
std::vector<int>findBM(std::string const & str, std::string const & text)
{
    vector<int>v;

    if( str == "" || text == "" || str.size() > text.size() )
        return v;

    for( int i = 0; i < 26; ++i )
    {
        shiftBM[i] = -1;
    }
    for( int i = 0; i < str.size(); ++i )
    {
        shiftBM[indeks(str[i])] = i;
    }

    int i = 0;

    while( i <= (text.size() - str.size()))
    {
        int j = str.size() - 1;

        while ( j >= 0 && str[j] == text[ i + j ] )
            --j;
        
        if( j < 0 )
        {
            v.push_back(i);
            if( i + str.size() < text.size() )
                i += str.size() - shiftBM[indeks(text[ i + str.size() ])];
            else
                i += 1;
            
        }
        else
            if( j - shiftBM[indeks( text[ i + j ])] > 0 )
                i += j - shiftBM[indeks( text[ i + j ])];
            else
                ++i;    
    }
    return v;
}

void write(vector<int>v)
{
    for( int i = 0; i < v.size(); ++i )
        cout << v[i] << " ";
}

#endif