#include <iostream>
#include <TreeMap.hpp>
#include <loadWords.hpp>
#include <load.hpp>


using namespace std;

int main()
{
    TreeMap<string,int> tree = read2tree("pan-tadeusz.txt");

    //tree.insert(0,0);
    //write(tree.root);

    return 0;
}