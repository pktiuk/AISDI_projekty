#include <iostream>
#include <chrono>
#include <utility>

/*!
 *  Narzedzie do zliczania czasu
 *
 *  Sposob uzycia:
 *
 *  {
 *    Benchmark<std::chrono::nanoseconds> b;
 *    // kod do zbadania
 *    size_t elapsed = b.elapsed();
 *  }
 *
 *  lub
 *
 *  {
 *    Benchmark<std::chrono::milliseconds> b(true);
 *    // kod do zbadania
 *  } // obiekt wypisze wartosc czasu w podanych jednostkach na stderr
 */
template<typename D = std::chrono::microseconds>
class Benchmark {
public:

    Benchmark(bool printOnExit = false) : m_print(printOnExit) {
        start = std::chrono::high_resolution_clock::now();
    }
    typename D::rep elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<D>(end-start);
        return result.count();
    }
    ~Benchmark() {
        auto result = elapsed();
        if (m_print)
        {
            std::cerr << "Czas: " << result << "\n";
        }
    }
private:
    std::chrono::high_resolution_clock::time_point start;
    bool m_print = true;
};


template<typename KeyType, typename ValueType>
struct element
{
    KeyType key;
    ValueType value;
    element* leftChild;
    element* rightChild;
    element* parent;
};


/*
 * Slownik
 */
template<typename KeyType, typename ValueType>
class TreeMap
{
  public:
    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;

    element<key_type, mapped_type>* root = NULL;

    int high = 0;
    int balance = 0;

    TreeMap() = default;    // konstruktor trywialny
    ~TreeMap()
    {
        clear(root);
    }

    void clear(element<key_type, mapped_type>& x)
    {
        if(x==NULL)
        {
            return;
        }
        else
        {
            clear(x->leftChild);
            clear(x->rightChild);
        }
        x->leftChild = NULL;
        x->rightChild = NULL;
        x->parent = NULL;
        delete x;

    }

    /*!
     * true jezeli slownik jest pusty
     */
    bool isEmpty() const
    {
        //throw std::runtime_error("TODO: isEmpty");
        if( root == NULL )
            return true;
        else
            return false;
        
    }

    void leftRotation(element<key_type, mapped_type>& x)
    {
        element<key_type, mapped_type>* y = x->parent;
        y->rightChild = x->leftChild;
        x->leftChild = y;
        x->parent = y->parent;
        y->parent = x;
    }

    void rightRotataion(element<key_type, mapped_type>& x)
    {
        element<key_type, mapped_type>* y = x->parent;
        y->leftChild = x->rightChild;
        x->rightChild = y;
        x->parent = y->parent;
        y->parent = x;
    }

    void avl(element<key_type, mapped_type>& x)
    {
        while( x->parent != NULL )
        {
            if( x->parent->parent == NULL )
            {
                if( x == x->parent->leftChild )
                {
                    rightRotataion(x);
                }
                else
                {
                    leftRotation(x);
                } 
            }
            else
            if( x->parent == x->parent->parent->leftChild && x == x->parent->leftChild )
            {
                rightRotataion(x->parent);
                rightRotataion(x);
            }
            else
            if( x->parent == x->parent->parent->rightChild && x == x->parent->rightChild )
            {
                leftRotataion(x->parent);
                leftRotataion(x);
            }
            else
            {
                if( x == x->parent->rightChild )
                {
                    leftRotation(x);
                    rightRotataion(x);
                }
                else
                {
                    rightRotataion(x);
                    leftRotation(x);
                }
            }
        }
        
        
    }

    /*!
     * dodaje wpis do slownika
     */
    void insert(const key_type& key, const mapped_type &value)
    {
        //throw std::runtime_error("TODO: insert");
        if(isEmpty())
        {
            root = new element<key_type, mapped_type>;
            root->key = key;
            root->value = value;
            root->leftChild = NULL;
            root->rightChild = NULL;
            root->parent = NULL;
        }
        else
        {

        }
    }

    /*!
     * dodaje wpis do slownika przez podanie pary klucz-wartosc
     */
    void insert(const value_type &key_value)
    {
        throw std::runtime_error("TODO: insert");
    }

    /*!
     * zwraca referencje na wartosc dla podanego klucza
     *
     * jezeli elementu nie ma w slowniku, dodaje go
     */
    mapped_type& operator[](const key_type& key)
    {
        throw std::runtime_error("TODO: operator[]");
    }

    /*!
     * zwraca wartosc dla podanego klucza
     */
    const mapped_type& value(const key_type& key) const
    {
        throw std::runtime_error("TODO: value");
    }

    /*!
     * zwraca informacje, czy istnieje w slowniku podany klucz
     */
    bool contains(const key_type& key) const {
        throw std::runtime_error("TODO: contains");
    }

    /*!
     * zwraca liczbe wpisow w slowniku
     */
    size_t size() const {
        throw std::runtime_error("TODO: size");
    }
private:

};


int main()
{
    //unit_test();

    return 0;
}
