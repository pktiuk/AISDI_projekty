#ifndef SEARCH

#define SEARCH

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 1000000;

char randomChar()
{
    return 'a' + rand() % 3;
}

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

int shift[MAX_SIZE];

std::vector<int>findKMP(std::string const & str, std::string const & text)
{
    vector<int>v;

    //init shift table
    shift[0] = -1;

    for( int i = 0, j = -1; i < str.size(); ++i, ++j, shift[i] = j )
    {
        while( ( j >= 0 ) && ( str[i] != str[j] ) )
            j = shift[j];
    }

    for( int i = 0, j = 0; i < text.size(); ++i, ++j )
    {
        if( j == str.size() )
        {
            v.push_back(i - str.size());
            j = shift[j];
        }
        while( j >=0 && text[i]!=str[j])
        {
            j=shift[j];
        }
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

    for( int i = 0; i < 26; ++i )
    {
        shiftBM[i] = -1;
    }
    for( int i = 0; i < str.size(); ++i )
    {
        shiftBM[indeks(str[i])] = i;
    }

    int s = 0;

    while( s <= (text.size() - str.size()))
    {
        int j = str.size() - 1;

        while ( j >= 0 && str[j] == text[ s + j ] )
            --j;
        
        if( j < 0 )
        {
            v.push_back(s);
            if( s + str.size() < text.size() )
                s += str.size() - shiftBM[indeks(text[ s + str.size() ])];
            else
                s += 1;
            
        }
        else
            s += max( 1, j - shiftBM[indeks( text[ s + j ])]);        
    }
    return v;
}

void write(vector<int>v)
{
    for( int i = 0; i < v.size(); ++i )
        cout << v[i] << " ";
}

#endif