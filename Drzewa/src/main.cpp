#include <TreeMap.hpp>
#include <loadWords.hpp>
#include <iostream>
#include <load.hpp>
#include <map>
#include <random>

using namespace std;


void loadTest()
{
  size_t sysTime, myTime;
  for (int i = 10; i < 50000; i = i + 100)
  {
    Benchmark<std::chrono::nanoseconds> b;
    TreeMap<string, int> tree = read2tree("pan-tadeusz.txt", i);
    myTime = b.elapsed();
    Benchmark<std::chrono::nanoseconds> b2;
    map<string, int> sysMap = read2map("pan-tadeusz.txt", i);
    sysTime = b2.elapsed();
    cout << i << " " << myTime << " " << sysTime << endl;
  }
}

void searchTest()
{
  size_t sysTime, myTime;
  int num;
  for (int i = 10; i < 50000; i = i + 100)
  {
    TreeMap<string, int> tree = read2tree("pan-tadeusz.txt", i);
    map<string, int> sysMap = read2map("pan-tadeusz.txt", i);
    num= random()%i;
    std::vector<string> vec=read("pan-tadeusz.txt", i);
    Benchmark<std::chrono::nanoseconds> b;
    tree.value(vec[num]);
    myTime = b.elapsed();
    Benchmark<std::chrono::nanoseconds> b2;
    sysMap.find(vec[num]);
    sysTime = b2.elapsed();
    cout << i << " " << myTime << " " << sysTime << endl;
  }
}

int main()
{
  
  searchTest();
  return 0;
}