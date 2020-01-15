#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>

#define X_SIZE 6
#define Y_SIZE 6

#define loc_to_i(x, y) x + X_SIZE *y
#define i_to_loc(a) [a % X_SIZE][a / X_SIZE]

using namespace std;

typedef struct node
{
  int distance;
  int distance_to_beginning;
  node *previous_node;
};

typedef class graph
{
private:
  /* data */
public:
  node nodes[X_SIZE][Y_SIZE];

  list<int> queque;
  int x;
  int y;
  graph(string &filename);
  ~graph();

  void dijkstra();
  int getFromQueque();
};

graph::graph(string &filename)
{
  ifstream file;
  file.open("file", ios_base::in);
  for (int i = 0; i < X_SIZE; i++)
  {
    string s;
    file >> s;
    for (int j = Y_SIZE; j >= 0; j--)
    {
      nodes[i][j].distance = s[j] - '0';
      nodes[i][j].distance_to_beginning = INT64_MAX;
    }
  }
  file.close();
  nodes[0][0].distance_to_beginning = 0;
  queque.push_back(loc_to_i(0, 0));
}

int graph::getFromQueque()
{
  if (queque.empty())
    return -1;
  list<int>::iterator smallestIter = queque.end();
  int smallestDistance = INT64_MAX;
  for (list<int>::iterator iter = queque.begin(); iter != queque.end(); iter++)
  {
    if (nodes i_to_loc(*iter).distance_to_beginning < smallestDistance)
    {
      smallestDistance = nodes i_to_loc(*iter).distance_to_beginning;
      smallestIter = iter;
    }
  }

  queque.erase(smallestIter);
  return smallestDistance;
}

void graph::dijkstra()
{
  while (!queque.empty())
  {
      //update neighbours
  }
}

graph::~graph() {}
