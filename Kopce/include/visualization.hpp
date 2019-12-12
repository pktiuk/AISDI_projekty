#include <heap.hpp>
#include <iostream>



template <typename KeyType, typename ValueType>
void visualizeHeap(Heap4<KeyType,ValueType> & heap)
{
    int height=heap.getHeight();
    int nextEndl=1;
    int currHeight=1;
    int nodesOnNextHeight=4;
    for (int i = 0 - 1; i < heap.heap.size(); i++)
    {
        if(i==nextEndl)
        {
            std::cout<<std::endl;
            nextEndl+=nodesOnNextHeight;
            nodesOnNextHeight*=4;
        }
        std::cout<<heap.heap[i].get<KeyType>();
        int parentOfCurrent=i/4;
        if(parentOfCurrent == (i+1)/4)
        {
            std::cout<<"       ";
        }else
        {
            std::cout<<"   |   ";
        }
    }
    return;
}