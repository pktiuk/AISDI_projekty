#include<searching.h>


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

//geeksforgeeks
bool testBM(int s)
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
    v = findBM(str, text);

    if( v == vN )
        return true;
    return false;
}