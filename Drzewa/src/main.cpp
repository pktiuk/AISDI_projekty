#include <TreeMap.hpp>
#include <loadWords.hpp>
#include <iostream>
#include <load.hpp>
#include <map>
#include <random>
#include <vector>

using namespace std;


void loadTest()
{
	vector<string>v;
  size_t sysTime, myTime;

	ifstream inFile;
	string word;
	inFile.open("pan-tadeusz.txt");
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (inFile >> word)
	{
		v.push_back(word);
	}
	inFile.close();

	TreeMap<string, int> tree = TreeMap<string, int>();
	map<string, int> sysMap;
  for (int i = 0; i < v.size(); ++i)
  {
    Benchmark<std::chrono::nanoseconds> b;
    read2tree(tree, v[i], i);
    myTime = b.elapsed();
    Benchmark<std::chrono::nanoseconds> b2;
    read2map(sysMap, v[i], i);
    sysTime = b2.elapsed();
	if( i%100 == 0 )
    	cout << i << " " << myTime << " " << sysTime << endl;
  }
}

void searchTest()
{
	
	vector<string>v;
  size_t sysTime, myTime;

	ifstream inFile;
	string word;
	inFile.open("pan-tadeusz.txt");
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (inFile >> word)
	{
		v.push_back(word);
	}
	inFile.close();

	TreeMap<string, int> tree = TreeMap<string, int>();
	map<string, int> sysMap;
  int num;
  for (int i = 1; i < v.size(); ++i)
  {
    num= random()%i;
	tree.insert(v[i],i);
	sysMap.emplace(v[i],i);
    Benchmark<std::chrono::nanoseconds> b;
    tree.value(v[num]);
    myTime = b.elapsed();
    Benchmark<std::chrono::nanoseconds> b2;
    sysMap.find(v[num]);
    sysTime = b2.elapsed();
	if( i%100 == 0 )
    	cout << i << " " << myTime << " " << sysTime << endl;
  }
  
}

int main()
{
  
  searchTest();
  return 0;
}