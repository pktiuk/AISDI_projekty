#ifndef HEAP
#define HEAP

#include <utility>
#include <vector>
#include<stdexcept>
	

using namespace std;

int const D = 3;

template <typename KeyType, typename ValueType,typename StreamType>
void visualizeHeap(const vector<pair<KeyType, ValueType> > &heapVec,StreamType &stream,  int nr =0, int depth =0)
{

    for(int i=0;i<depth;i++)
    {
        stream<<"    ";
    }
    stream<<heapVec[nr].first<<endl;
    if(heapVec.size()>=nr*3+1)
    {
        visualizeHeap(heapVec,stream,nr*3+1,depth+1);
    }
    if(heapVec.size()>=nr*3+2)
    {
        visualizeHeap(heapVec,stream,nr*3+2,depth+1);
    }
    if(heapVec.size()>=nr*3+3)
    {
        visualizeHeap(heapVec,stream,nr*3+3,depth+1);
    }
    return;
}

template <typename KeyType, typename ValueType>
class Heap3
{
public:
    using KeyValueType = std::pair<KeyType, ValueType>;

    bool empty() const noexcept
    {
        if(heap.size() == 0)
            return true;
        return false;
    }

    void insert(KeyType const & key, ValueType const & value);
    void insert(KeyValueType const & key_value);
    KeyValueType const & peek() const
    {
        if(!heap.empty())
            return heap[0];
        else
        {
            std::logic_error e("messag");
            throw e;
        }
    }
    KeyValueType pop() noexcept;
    size_t size() const noexcept
    {
        return heap.size();
    }

    vector<pair<KeyType, ValueType> >heap;

    int getHeight();

    template<typename StreamType> void print(StreamType& stream) const
    {
       visualizeHeap(heap,stream);
    }

    Heap3(/* args */){};
    ~Heap3(){};
};

template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> Heap3<KeyType, ValueType>::pop() noexcept
{
    pair<const KeyType, ValueType> result = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    int current = 0;
    while( current*D + 1 < heap.size() )
    {
        int minimum = heap[current*D+1].first;
        for( int i = 1; i < 3; ++i )
        {
            if(current*D + i < heap.size())
                minimum = min(minimum, heap[current*D+i].first);
        }
        
        if(minimum >= heap[current].first)
            break;
        int next = current*D+1;
        while(heap[next].first != minimum)
        {
            next++;
        }
        std::pair<const KeyType, ValueType> tmp = make_pair(heap[current].first, heap[current].second);
        heap[current] = heap[next];
        heap[next] = tmp;

        current = next;
    }
    return result;
}

template <typename KeyType, typename ValueType>
void Heap3<KeyType, ValueType>::insert(KeyType const & key, ValueType const & value)
{
    insert(make_pair(key, value));
}

template <typename KeyType, typename ValueType>
void Heap3<KeyType, ValueType>::insert(std::pair<KeyType, ValueType> const & key_value)
{
    heap.push_back(key_value);
    
    int myNumber = heap.size()-1;
    int parent = (myNumber-1)/D;

    while( myNumber != 0 && heap[parent] > heap[myNumber] )
    {
        std::pair<KeyType, ValueType> tmp = heap[parent];
        heap[parent] = make_pair(heap[myNumber].first, heap[myNumber].second);
        heap[myNumber] = tmp;
        
        myNumber = parent;
        parent = (myNumber-1)/D;
    }

}



template <typename KeyType, typename ValueType>
int Heap3<KeyType, ValueType>::getHeight()
{
    if(heap.empty())
        return 0;
    int height = 1;
    int i = 0;
    while( i < heap.size()-1 )
    {
        i = i * 3 + 3 ;
        height ++;
    }
    return height;
}



#endif