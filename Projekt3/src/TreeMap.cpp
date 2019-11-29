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
    int balance = 0;
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

    void updateBalancell(element<key_type, mapped_type>& x, element<key_type, mapped_type>& y)
    {
        if(x->balance == 1)
        {
            x->balance = 0;
            y->balance = 0;
        }
        else
        {
            y->balance = 1;
            x->balance = -1;
        }
    }

    void updateBalancerr(element<key_type, mapped_type>& x, element<key_type, mapped_type>& y)
    {
        if(x->balance == -1)
        {
            x->balance = 0;
            y->balance = 0;
        }
        else
        {
            y->balance = -1;
            x->balance = 1;
        }
    }

    void leftRotation(element<key_type, mapped_type>& x, bool doUpdate = true)
    {
        element<key_type, mapped_type>* y = x->parent;
        y->rightChild = x->leftChild;
        x->leftChild = y;
        x->parent = y->parent;
        y->parent = x;

        if(doUpdate)
        {
            updateBalancell(x, y);
        }

    }

    void rightRotataion(element<key_type, mapped_type>& x, bool doUpdate = true)
    {
        element<key_type, mapped_type>* y = x->parent;
        y->leftChild = x->rightChild;
        x->rightChild = y;
        x->parent = y->parent;
        y->parent = x;

        if(doUpdate)
        {
            updateBalancerr(x, y);
        }
    }

    void lr(element<key_type, mapped_type>& b)
    {
        element<key_type, mapped_type>* c = b->rightChild;
        element<key_type, mapped_type>* a = b->parent;
        rightRotataion(c, false);
        leftRotation(c, false);

        if(c->balance == 1)
            a->balance = -1;
        else
            a->balance = 0;
        if(c->balance == -1)
            b->balance = 1;
        else
            b->balance = 0;

    }

    void rl(element<key_type, mapped_type>& b)
    {
        element<key_type, mapped_type>* c = b->leftChild;
        element<key_type, mapped_type>* a = b->parent;
        leftRotation(c, false);
        rightRotataion(c, false);

        if(c->balance == -1)
            a->balance = 1;
        else
            a->balance = 0;
        if(c->balance == 1)
            b->balance = -1;
        else
            b->balance = 0;
        

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
     * jesli go nie znajdzie zwraca NULL
     */
    const mapped_type& value(const key_type& key) const
    {
        //throw std::runtime_error("TODO: value");
        element<key_type, mapped_type>* tmp = root;
        while( tmp != NULL )
        {
            if(tmp->key == key)
            {
                return tmp->value;
            }
            else
            if(key < tmp->key)
                tmp = tmp->leftChild;
            else
                tmp = tmp->rightChild;
        }
        return NULL;
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

    void write()
private:

};


int main()
{
    //unit_test();

    return 0;
}
