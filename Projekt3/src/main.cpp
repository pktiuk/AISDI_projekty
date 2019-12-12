#include <TreeMap.hpp>
#include <iostream>
#include <load.hpp>
#include <loadWords.hpp>
#include <map>

using namespace std;

int main()
{
  size_t sysTime, myTime;
  for (int i = 10; i < 50000; i = i + 100)
  {
    Benchmark<std::chrono::nanoseconds> b;
    TreeMap<string, int> tree = read2tree("pan-tadeusz.txt", 1000);
    myTime = b.elapsed();
    Benchmark<std::chrono::nanoseconds> b2;
    map<string, int> sysMap = read2map("pan-tadeusz.txt", 1000);
    sysTime = b2.elapsed();
    cout << i << " " << myTime << " " << sysTime << endl;
  }

  return 0;
}