#include "../lib/bubblesort.hpp"

template <typename IteratorType> void bubbleSort(IteratorType first, IteratorType last)
{
  bool sorted = false;
  while (!sorted)
  {
      sorted=true;
    for (IteratorType curr; curr != last; curr++)
    {
      if (*curr > *(curr + 1))
      {
        std::swap(curr, curr + 1);
        sorted=false;
      }
    }
  }
}