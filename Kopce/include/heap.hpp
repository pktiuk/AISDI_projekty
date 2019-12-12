#include <utility>


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

    Heap4(/* args */){};
    ~Heap4(){};
};

