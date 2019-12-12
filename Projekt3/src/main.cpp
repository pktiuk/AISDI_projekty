#include <iostream>
#include <TreeMap.hpp>
#include <loadWords.hpp>
#include <load.hpp>


using namespace std;

int main()
{
    TreeMap<string,int> tree = read2tree("pan-tadeusz.txt", 12);

    //tree.insert(0,0);
    cout << tree.root->key << "\n";
    cout << tree.root->leftChild->key << "\n";
    cout << tree.root->rightChild->key << "\n";
    //tree.write(tree.root);

    //cout << tree.value("panicza");

    return 0;
}