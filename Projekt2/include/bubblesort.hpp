#include <algorithm>
#include <vector>
#include <string>


template <typename IteratorType> 
void bubbleSort(IteratorType first, IteratorType last)
{
  bool sorted = false;
  while (!sorted)
  {
    sorted=true;
    for (auto current=next(first,0); current != last; current++)
    {
      if ((*current) > (*(current + 1)))
      {
        std::iter_swap(current, current + 1);
        sorted=false;
      }
    }
  }
}