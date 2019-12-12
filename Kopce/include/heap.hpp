#include <utility>
#include <vector>

using namespace std;

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

    vector<KeyValueType>heap;

    int getHeight();

    template<typename StreamType> void print(StreamType& stream) const;

    Heap4(/* args */){};
    ~Heap4(){};
};

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



