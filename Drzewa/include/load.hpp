#include <TreeMap.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    tree.insert(word, i);
    i++;
  }
  inFile.close();
  return tree;
}

map<string,int> read2map(string filename, int num = INT32_MAX)
{
  int i = 0;
  ifstream inFile;

  map<string, int> sysMap;

  inFile.open(filename);

  if (!inFile)
  {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }

  string word;

  while (inFile >> word && i < num)
  {
    sysMap.emplace(word,i);
    i++;
  }
  
  inFile.close();
  return sysMap;
}