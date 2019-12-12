#include <iostream>
#include <TreeMap.hpp>
#include <loadWords.hpp>
#include <load.hpp>


using namespace std;

int main()
{
    TreeMap<string,int> tree = read2tree("pan-tadeusz.txt", 1000);

    //tree.insert(0,0);
    //cout << tree.root->key << "\n";
    //cout << tree.root->leftChild->key << "\n";
    //cout << tree.root->rightChild->key << "\n";
    //cout << "write\n";
    //tree.write();

    //cout << tree.value("czyli") << "\n";
    cout << tree.value("Dom") << "\n";
   

    return 0;
}