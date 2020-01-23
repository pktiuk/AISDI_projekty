#include <fstream>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <cmath>

#define X_SIZE 7
#define Y_SIZE 7

#define loc_to_i(x, y) x + X_SIZE *y
//#define i_to_x(a) 
//#define i_to_y(a) (a / X_SIZE)

const int MAX_NUMBER = 1000000;

using namespace std;

int i_to_x(int a)
{
    return (a % X_SIZE);
}

int i_to_y(int a)
{
    return (a / X_SIZE);
}


#define i_to_loc(a) [i_to_x(a)][i_to_y(a)]

typedef struct node
{
  int distance;
  int distance_to_beginning;
  int distance_to_beginning_with_h;
  int previous_node;
  int h;
} node;

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
  void h();

  void a();
  void updateNeighbour(int current_nr, int neighbour_nr);
  int getFromQueque();
  void visualize();
} graph;

graph::graph(const char *filename)
    : found_way(false)
{
  ifstream file;
  file.open(filename, ios_base::in);
  for (int j = 0; j < Y_SIZE; j++)
  {
    string s;
    file >> s;
    for (int i = 0; i < X_SIZE; i++)
    {
      nodes[i][j].distance = s[i] - '0';
      nodes[i][j].distance_to_beginning = MAX_NUMBER;
      nodes[i][j].distance_to_beginning_with_h = MAX_NUMBER;
      nodes[i][j].previous_node = -1;
      nodes[i][j].h=0;
      queque.push_back(loc_to_i(i, j));
    }
  }
  file.close();
  nodes[X_SIZE-1][0].distance_to_beginning = 0;
  h();
}

int graph::getFromQueque()
{
  if (queque.empty())
    return -1;
  list<int>::iterator smallestIter = queque.end();
  int smallestDistance = MAX_NUMBER;
  for (list<int>::iterator iter = queque.begin(); iter != queque.end(); iter++)
  {
    int currDistance = nodes i_to_loc(*iter).distance_to_beginning + nodes i_to_loc(*iter).h;
    if (currDistance < smallestDistance)
    {
      smallestDistance = currDistance;
      smallestIter = iter;
    }
  }
    int result=*smallestIter;
  queque.erase(smallestIter);
  return result;
}

void graph::updateNeighbour(int current_nr, int neighbour_nr)
{
  int new_distance = nodes i_to_loc(current_nr).distance_to_beginning + nodes i_to_loc(neighbour_nr).distance + nodes i_to_loc(neighbour_nr).h;
  if (new_distance < nodes i_to_loc(neighbour_nr).distance_to_beginning_with_h)
  {
    nodes i_to_loc(neighbour_nr).previous_node = current_nr;
    nodes i_to_loc(neighbour_nr).distance_to_beginning_with_h = new_distance;
    nodes i_to_loc(neighbour_nr).distance_to_beginning = nodes i_to_loc(current_nr).distance_to_beginning + nodes i_to_loc(neighbour_nr).distance;
  }
  if (neighbour_nr == (Y_SIZE - 1)*X_SIZE)
    found_way = true;
}

void graph::a()
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
  cout << "Map:\n";
  for (int i = 0; i < X_SIZE; i++)
  {
    for (size_t j = 0; j < Y_SIZE; j++)
    {
      cout << nodes[j][i].distance;
    }
    cout << endl;
  }
  
  cout << "H:\n";
  for (int i = 0; i < X_SIZE; i++)
  {
    for (size_t j = 0; j < Y_SIZE; j++)
    {
      cout << nodes[j][i].h << " ";
    }
    cout << endl;
  }
  cout << "distance_to_b:\n";
  for (int i = 0; i < X_SIZE; i++)
  {
    for (size_t j = 0; j < Y_SIZE; j++)
    {
      cout << nodes[j][i].distance_to_beginning << " ";
    }
    cout << endl;
  }
  
  cout << endl << "Found way:\n";

  char way[X_SIZE][Y_SIZE];
  for (size_t i = 0; i < X_SIZE; i++)
  {
    for (size_t j = 0; j < Y_SIZE; j++)
    {
      way[i][j] = ' ';
    }
  }
  int curr_num = (Y_SIZE-1)*X_SIZE;
  while (curr_num != X_SIZE - 1)
  {
    way i_to_loc(curr_num) = nodes i_to_loc(curr_num).distance + '0';
    curr_num = nodes i_to_loc(curr_num).previous_node;
    if (curr_num == -1)
    {
      cout << "ERROR";
      //return;
    }
  }
  way[X_SIZE - 1][0] = '0';

  for (int i = 0; i < X_SIZE; i++)
  {
    for (int j = 0; j < Y_SIZE; j++)
    {
      cout << way[j][i];
    }
    cout << endl;
  }
  cout << endl << "Distance: " << nodes[X_SIZE - 1][Y_SIZE - 1].distance_to_beginning << endl;
}

void graph::h()
{
    int cur = ( Y_SIZE - 1 ) * X_SIZE;

    nodes i_to_loc(cur).h = 0;
    cur++;

    while( cur>=0 )
    {
        if(cur%X_SIZE == 0)
        {
            nodes i_to_loc(cur).h = nodes i_to_loc(cur + X_SIZE).h + nodes i_to_loc(cur).distance;
        }
        else
        if(cur > ( Y_SIZE - 1 ) * X_SIZE )
        {
            cout << "X:"<<i_to_x(cur-1) << " ";
            cout << i_to_y(cur-1) << endl;
            int tmp1 = nodes i_to_loc(cur -1).h;
            int tmp2 = nodes i_to_loc(cur).distance;
            nodes i_to_loc(cur).h = tmp1 + tmp2;
        }
        else
        {
            nodes i_to_loc(cur).h = min(nodes i_to_loc(cur - 1).h, nodes i_to_loc(cur + X_SIZE).h) + nodes i_to_loc(cur).distance; 
        }

        //
        cur++;
        if(cur%X_SIZE==0)
        {
            cur-=(X_SIZE*2);
        }
    }
}

graph::~graph() {}


