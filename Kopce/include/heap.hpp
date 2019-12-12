#ifndef HEAP
#define HEAP

#include <utility>
#include <vector>

using namespace std;

int const D = 4;

template <typename KeyType, typename ValueType>
class Heap4
{
public:
    using KeyValueType = std::pair<const KeyType, ValueType>;

    bool empty() const noexcept
    {
        return true;
    }
    void insert(KeyType const & key, ValueType const & value);
    void insert(KeyValueType const & key_value);
    KeyValueType const & peek() const noexcept;
    KeyValueType pop() noexcept;
    size_t size() const noexcept;

    vector<pair<KeyType, ValueType> >heap;

    int getHeight();

    template<typename StreamType> void print(StreamType& stream) const;

    Heap4(/* args */){};
    ~Heap4(){};
};

template <typename KeyType, typename ValueType>
std::pair<const KeyType, ValueType> Heap4<KeyType, ValueType>::pop() noexcept
{
    pair<const KeyType, ValueType> result = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    int current = 0;
    while( current*D+D < heap.size() )
    {
        int maksimum = max(max(heap[current*D+1], heap[current*D +2]), max(heap[current*D+3], heap[current*D +4]));
        if(maksimum <= heap[current])
            break;
        int next = current*D+1;
        while(heap[next] != maksimum)
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
void Heap4<KeyType, ValueType>::insert(KeyType const & key, ValueType const & value)
{
    insert(make_pair(key, value));
}

template <typename KeyType, typename ValueType>
void Heap4<KeyType, ValueType>::insert(std::pair<const KeyType, ValueType> const & key_value)
{
    cout<<"insert\n";
    heap.push_back(key_value);
    
    int myNumber = heap.size()-1;
    int parent = (myNumber-1)/D;

    while( myNumber != 0 && heap[parent] < heap[myNumber] )
    {
        std::pair<KeyType, ValueType> tmp = heap[parent];
        heap[parent] = make_pair(heap[myNumber].first, heap[myNumber].second);
        heap[myNumber] = tmp;
        
        myNumber = parent;
        parent = (myNumber-1)/D;
    }

}



template <typename KeyType, typename ValueType>
int Heap4<KeyType, ValueType>::getHeight()
{
    if(heap.empty())
        return 0;
    int height = 1;
    int i = 0;
    while( i < heap.size()-1 )
    {
        i = i * 4 + 4 ;
        height ++;
    }
    return height;
}



#endif