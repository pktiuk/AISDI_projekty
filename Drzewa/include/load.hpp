#include <TreeMap.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void read2tree(TreeMap<string, int>& tree, string s, int num = INT32_MAX)
{
  tree.insert(s, num);
}

void read2map(map<string, int>& sysMap, string s, int num = INT32_MAX)
{
    sysMap.emplace(s,num);

}