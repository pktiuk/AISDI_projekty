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
    return c - 'a' + 1;
}

/*
 * nie dziala
*/
std::vector<int>findBM(std::string const & str, std::string const & text)
{
    vector<int>v;

    for( int i = 0; i < 26; ++i )
    {
        shift[i] = str.size();
    }
    for( int i = 0; i < str.size(); ++i )
    {
        shift[indeks(str[i])] = str.size() - i - 1;
    }

    for( int i = str.size() - 1, j = str.size() - 1; j > 0; --i, --j )
    {
        while( text[i] != str[j] )
        {
            int x = shift[indeks(text[i])];
            if( str.size() - j > x )
                i += str.size() - j;
            else
                i += x;
            if( i >= text.size() )
                return v;
            j = str.size() - 1;
        }
        v.push_back(i);
    }
    return v;
}

void write(vector<int>v)
{
    for( int i = 0; i < v.size(); ++i )
        cout << v[i] << " ";
}

bool testN()
{
    vector<int> v;
    string text;
    string str;
    

    /* test 1 */
    text = "abbababa";
    str = "ab";

    v = findN(str, text);

    if( v.size() != 3 ) 
        return false;
    if( v[0] != 0 || v[1] != 3 || v[2] != 5 )
        return false;

    v.clear();

    /* test 2 */
    text = "alamakotaatamaramapsa";
    str = "ta";

    v = findN(str, text);

    if( v.size() != 2 ) 
        return false;
    if( v[0] != 7 || v[1] != 10)
        return false;

    v.clear();

    /* test 3 */
    text = "fualhdakvjsboieqhaudfl.asvap'parihwral;hgsfbnciwrahw";
    str = "";

    v = findN(str, text);

    if( v.size() != 0 ) 
        return false;

    v.clear();

    /* test 4 */
    text = "";
    str = "napis";

    v = findN(str, text);

    if( v.size() != 0 ) 
        return false;

    v.clear();

    /* test 5 */
    text = "";
    str = "";

    v = findN(str, text);

    if( v.size() != 0 ) 
        return false;

    v.clear();

    /* test 6 */
    text = "gjsfbjvuetkbvlulsapwrgphdfadfasghsfsfdshsdghkry";
    str = "gjsfbjvuetkbvlulsapwrgphdfadfasghsfsfdshsdghkry";

    v = findN(str, text);

    if( v.size() != 1 ) 
        return false;
    if( v[0] != 0)
        return false;

    v.clear();

    /* test 7 */
    text = "gjsfbjvuetkbvlulsapwrgphdfadfasghsfsfdshsdghkr";
    str = "gjsfbjvuetkbvlulsapwrgphdfadfasghsfsfdshsdghkry";

    v = findN(str, text);

    if( v.size() != 0 ) 
        return false;

    v.clear();

    /* test 8 */
    text = "qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm";
    str = "qwa";

    v = findN(str, text);

    if( v.size() != 0 ) 
        return false;

    v.clear();

    return true;
}

bool testKMP(int s)
{
    srand(s);
    vector<int> v;
    vector<int> vN;
    string text = "";
    string str = "";

    for( int i = 0; i < 6; ++i )
        str += randomChar();
    for( int i = 0; i < 200000; ++i )
        text += randomChar();

    vN = findN(str, text);
    v = findKMP(str, text);

    if( v == vN )
        return true;
    return false;
}

bool testBM(int s)
{
    srand(s);
    vector<int> v;
    vector<int> vN;
    string text = "";
    string str = "";

    for( int i = 0; i < 2; ++i )
        str += randomChar();
    for( int i = 0; i < 20; ++i )
        text += randomChar();

    cout << text << " " << str << "\n";

    vN = findN(str, text);
    v = findBM(str, text);

    cout << "vN\n";
    write(vN);
    cout << "v\n";
    write(v);

    if( v == vN )
        return true;
    return false;
}

int main()
{
    cout<<"naiwny: ";
    if(testN())
        cout<<"OK\n";
    else
        cout<<"ERROR\n";

    cout << "KMP: ";
    if(testKMP(1))
        cout << "OK\n";
    else
        cout << "ERROR\n";

    cout << "BM: ";
    if(testBM(1))
        cout << "OK\n";
    else
        cout << "ERROR\n";
    
}