#include <heap.hpp>
#include <iostream>

using namespace std;

template <typename KeyType, typename ValueType>
void visualizeHeap(Heap3<KeyType,ValueType> & heap, int nr =0, int depth =0)
{

    for(int i=0;i<depth;i++)
    {
        cout<<"    ";
    }
    cout<<heap.heap[nr].first<<endl;
    if(heap.heap.size()>=nr*3+1)
    {
        visualizeHeap(heap,nr*3+1,depth+1);
    }
    if(heap.heap.size()>=nr*3+2)
    {
        visualizeHeap(heap,nr*3+2,depth+1);
    }
    if(heap.heap.size()>=nr*3+3)
    {
        visualizeHeap(heap,nr*3+3,depth+1);
    }
    return;
}