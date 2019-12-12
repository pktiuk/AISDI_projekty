#include <TreeMap.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TreeMap<string, int> read2tree(string filename, int num = INT32_MAX)
{
  int i = 0;
  ifstream inFile;

  TreeMap<string, int> tree = TreeMap<string, int>();

  inFile.open(filename);

  if (!inFile)
  {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }

  string word;

  while (inFile >> word && i < num)
  {
    cout << word << " " << i << "\n";
    tree.insert(word, i);
    i++;
  }

  return tree;
}