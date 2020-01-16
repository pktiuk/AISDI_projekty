#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>

#define X_SIZE 6
#define Y_SIZE 6

#define loc_to_i(x, y) x + X_SIZE *y
#define i_to_loc(a) [a % X_SIZE][a / X_SIZE]
#define i_to_x(a) a % X_SIZE
#define i_to_y(a) a / X_SIZE

using namespace std;

typedef struct node
{
  int distance;
  int distance_to_beginning;
  int previous_node;
}node;

typedef class graph
{
private:
  bool found_way;

public:
  node nodes[X_SIZE][Y_SIZE];

  list<int> queque;
  int x;
  int y;
  graph(const char *);
  ~graph();

  void dijkstra();
  void updateNeighbour(int current_nr, int neighbour_nr);
  int getFromQueque();
  void visualize();
}graph;

graph::graph(const char *filename)
    : found_way(false)
{
  ifstream file;
  file.open(filename, ios_base::in);
  for (int i = 0; i < X_SIZE; i++)
  {
    string s;
    file >> s;
    for (int j = Y_SIZE; j >= 0; j--)
    {
      nodes[i][j].distance = s[j] - '0';
      nodes[i][j].distance_to_beginning = INT32_MAX;
      nodes[i][j].previous_node = -1;
      queque.push_back(loc_to_i(i, j));
    }
  }
  file.close();
  nodes[0][0].distance_to_beginning = 0;
}

int graph::getFromQueque()
{
  if (queque.empty())
    return -1;
  list<int>::iterator smallestIter = queque.end();
  int smallestDistance = INT32_MAX;
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

void graph::updateNeighbour(int current_nr, int neighbour_nr)
{
  int new_distance = nodes i_to_loc(current_nr).distance_to_beginning + nodes i_to_loc(neighbour_nr).distance;
  if (new_distance < nodes i_to_loc(neighbour_nr).distance_to_beginning)
  {
    nodes i_to_loc(neighbour_nr).previous_node = current_nr;
    nodes i_to_loc(neighbour_nr).distance_to_beginning = new_distance;
  }
  if(neighbour_nr==X_SIZE*Y_SIZE-1)
    found_way=true;
}

void graph::dijkstra()
{
  int current;
  while (!queque.empty() && !found_way)
  {
    current = getFromQueque();

    // up
    if (i_to_y(current) != 0)
    {
      updateNeighbour(current, current - X_SIZE);
    }
    // down
    if (i_to_y(current) != Y_SIZE - 1)
    {
      updateNeighbour(current, current + X_SIZE);
    }

    // left
    if (i_to_x(current) != 0)
    {
      updateNeighbour(current, current - 1);
    }
    // right
    if (i_to_x(current) != X_SIZE - 1)
    {
      updateNeighbour(current, current + 1);
    }
  }
}


void graph::visualize()
{
  cout<<"Map:\n";
  for (int i = 0; i < X_SIZE; i++)
  {
    for (size_t j = 0; j < Y_SIZE; j++)
    {
      cout<<nodes[i][j].distance;
    }
    cout<<endl;
  }
  cout<<endl<<"Found way:\n";

}

graph::~graph() {}
